#include <iostream>
using namespace std;
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <wait.h>
#include <signal.h>
#include <cstring>
#include "lt.h"


void transact_with_client(int sock);

//to avoid zombie process
void sighandler(int signum)
{
	cout << strsignal(signum) << endl;
	wait(NULL);
}

int main(int argc , char *argv[])
{
	string uname,upass;
	int flag=0;
	if (argc == 1)
	{
		cout<<"Enter Username "<<endl;
		cin>>uname;
		cout<<"Enter Password "<<endl;
		cin>>upass;
		registr(uname,upass);	
		cout << "Registered Successfully .... " << endl;
	}
	else
	{
		string oper, filename;
		while(flag < 3)
		{
			cout<<"Enter Password "<<endl;
			cin>>upass;
			flag++;
			if (loginValidate(argv[1],upass))
			{
				cout << "login success" << endl;
				while(1)
				{	cout<< " >> ";
					cin >> oper  >> filename;
					char operation [30];
					strcpy(operation,oper.c_str());
					//strcpy(file,filename.c_str());
					if ( strcmp(operation,"add")==0)
					{
						add(filename);
					}
					else if (strcmp(operation,"edit")==0)
					{
						update("aaa", "bbb",filename);
					}
					else if (strcmp(operation,"remove")==0)
					{
						remove(filename);
					}
					else
					{
						cout << " Logging out successfully  ...." << endl;
						exit(0);
					}
				}
				break;
				
			}
			else
			{
				cout << "invalid credentials" << endl;
				if (flag==3)
				{
					exit(1);
				}
			}
		}
	}
		
		
	//signal disposition
	signal(SIGCHLD, sighandler);

	//socket creation
	int serv_fd = socket(AF_INET,SOCK_STREAM,0);
	if (serv_fd == -1)
	{
		perror("socket creation error");
		exit(1);
	}
	//initialize the sockaddr_in structure
	struct sockaddr_in sock_addr_serv;// sockaddr_in for IPV4
	sock_addr_serv.sin_family = AF_INET;
	sock_addr_serv.sin_port = 3306;
	sock_addr_serv.sin_addr.s_addr = inet_addr("127.0.0.1");

	//bind the socket with ip address and port
	if (bind(serv_fd,(struct sockaddr *)&sock_addr_serv,sizeof(sock_addr_serv))==-1)
	{
		perror("bind error");
		exit(1);
	}

	// listening (waiting) for client request
	if (listen(serv_fd,5)==-1)
	{
		perror("listen error");
		exit(1);
	}

	while (1)
	{
		cout << "server waiting for client to connect"  << endl;
		
		//accepting client request
		struct sockaddr_in sock_addr_cli;
		socklen_t cli_len = sizeof(sock_addr_cli);
		int client_fd=accept(serv_fd,(struct sockaddr *)&sock_addr_cli,&cli_len);
		
		//cout << "clinet port no. " << sock_addr_cli.sin_port << endl;
		
	 	if (client_fd==-1)
		{
			perror(" accept error");
			exit(1);
		}
		
		pid_t pid= fork();
		if (pid==0)
		{
			transact_with_client(client_fd);
			exit(0);
		}
		else if (pid > 0)
		{
			close(client_fd);
		}
		else
		{
			perror("error in fork");
			exit(1);
		}	
		
	}	

	//close socket
	if (close(serv_fd)==-1)
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
	
	
	
	
	
	
	



