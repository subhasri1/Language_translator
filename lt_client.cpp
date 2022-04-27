
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
 
	 
	
	 int main(int argc, char*argv)
	 {
	    string input string ENG[]={"black","blue","brown"};
	    string HIN[]={"kaala","neela","bhoora"};
	    cout<<"enter a word";
	    cin>>input;
	    for(int i=0;i<10;i++)
	    {
	       if(ENG[i]==input)
	       {
	          cout<<"you entered"<<HIN[i]<<endl;
	       }  
	    }
	    return 0;
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
	sock_addr_server.sin_addr.s_addr=inet_addr("127.0.0.01");

	//connecting
	socklen_t len=sizeof(sock_addr_server);
	if(connect(server_fd,(struct sockaddr *)&sock_addr_server,len)==-1)
		{
		perror("connect error");
		exit(1);
		}

	cout<<"in client client fd"<<server_fd<<endl;
	cout<<"in server port"<<sock_addr_server.sin_port<<endl;


	char ch='a';

	write(server_fd,&ch,1);
	read(server_fd,&ch,1);
	cout<<"from server"<<ch<<endl;
	close(server_fd);
	}
	
	    
	    	 
	
	  
