#include<iostream>
#include<sys/socket.h>
using namespace std;
#include<unistd.h>
#include<arpa/inet.h>
#include<errno.h>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<errno.h>
#include<signal.h>
#include<wait.h>
#include<cstring>
#include "lt.h"

void transact_with_client(int sock);
void sighandler(int signum)
	{
	cout<<strsignal(signum)<<endl;
	wait(NULL);
	}
 int main(int argc ,char * argv[])
 {
         string uname,upass;
         int flag=0;
         if(argc==1)
           {
              cout<<"enter username "<<endl;
              cin>>uname;
              cout<<"enter password "<<endl;
              cin>>upass;
              registr(uname,upass);
              cout<<"Registered successfully ...."<<endl;
            }
            else
            {
              string oper,filename;
              while(flag<3)
              {
                  cout<<"enter password"<<endl;
                  cin>>upass;
                  flag++;
                  if(loginValidate(argv[1],upass))
                  {
                     cout<<"login sucess"<<endl;
                     while(1)
                     {
                          cout<<">>";
                          cin>>oper>>filename;
                          char operation [30],file[30]; 
                          strcpy(operation,oper.c_str());
                          strcpy(file,filename.c_str());
                          if(strcmp(operation,"add")==0)
                          { 
                              add(file);
                          }
                           else if(strcmp(operation,"update")==0)
                           {  
                               update("aaa","bbb",filename);
                           }
                           else if(strcmp(operation,"remove")==0)
                           {
                                 remove(filename);
                           }
                           
                           else
                           {
                                cout<<"Logging out successfully...."<<endl;
                                exit(0);
;                          }
                    }
                    break;
                  }
                  else
                  {
                    cout<<"invalid credential"<<endl;
                    if(flag==3)
                    {
                        exit(1);
                     }
                   }
              }
      }
      signal(SIGCHLD, sighandler);                 
//socket creation
	int server_fd=socket(AF_INET,SOCK_STREAM,0);
	if(server_fd==-1)
		{
		perror("socket creation error");
		exit(1);
		}
	struct sockaddr_in sock_addr_server;
	sock_addr_server.sin_family=AF_INET;
	sock_addr_server.sin_port=3006;
	sock_addr_server.sin_addr.s_addr=inet_addr("127.0.0.1");

	//binding
	if(bind(server_fd,(struct sockaddr *)&sock_addr_server,sizeof(sock_addr_server))==-1)
		{
		perror("bind error");
		exit(1);
		}
	//listen
	if(listen(server_fd,5)==-1)
		{
		perror("listen error");
		exit(1);
		}
	//acceptance
	while(1)
	{
		cout<<"server waiting for client to connect"<<endl;
		struct sockaddr_in sock_addr_cli;
		socklen_t cli_len=sizeof(sock_addr_cli);
		int client_fd=accept(server_fd,(struct sockaddr *)&sock_addr_cli,&cli_len);
		//cout<<"in server serv fd"<<server_fd<<endl;
		//cout<<"in server client fd"<<client_fd<<endl;
		//cout<<"in server port"<<sock_addr_cli.sin_port<<endl;
		//cout<<"in server ip"<<sock_addr_cli.sin_addr.s_addr<<endl;
		if(client_fd==-1)
		{
			perror("accept error");
			exit(1);
		}
		pid_t pid=fork();
		if(pid==0)
		{
		    transact_with_client(client_fd);
		    exit(0);
		}
		else if(pid>0)
		{
		     close(client_fd);	
		}   
		else
		{
		     perror("error in fork");
		     exit(1);
		}	
       }
	
	if(close(server_fd)==-1)
	{
		perror("socket close error");
		exit(1);
	}

}
void transact_with_client(int sock)
{
     char ch[100];
     int n=recv(sock,ch,sizeof(ch),0);
     write(1,ch,strlen(ch));
 }
