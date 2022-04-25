#include <iostream>
using namespace std;
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void transact_with_server(int sd,int argc,char*argv[])
{
	if(argc<3)
	{
		cout<<"usage error"<<endl;
		exit(0)'
	}
	else if(argc==1)
	{
		cout<<"Enter Username "<<endl;
		cin>>uname;
		cout<<"Enter Password "<<endl;
		cin>>upass;
		int u=send(sd,uname,strlen(uname),0);
		int p=send(sd,upass,strlen(upass),0);
		char ubuff[100],pbuff[100];
		int m=recv(sd,ubuff,sizeof(ubuff),0);
		int n=recv(sd,pbuff,sizeof(pbuff),0);
		write(1,ubuff,m);
		write(1,pbuff,n);
	}
	/*
	else
	{
		int n=send(sd,argv[2],strlen(argv[2]),0);
		char buf[100];
		int m=recv(sd,buff,sizeof(buf),0);
		write(1,buf,m);
	}
	
	*/
}


int main(int argc,char*argv[])
{

//socket creation
int serv_fd = socket(AF_INET,SOCK_STREAM,0);
if (serv_fd == -1)
{
	perror("socket creation error");
	exit(1);
}
//initialize the socaddr_in structure
struct sockaddr_in sock_addr_serv;// sockaddr_in for IPV4
sock_addr_serv.sin_family = AF_INET;
sock_addr_serv.sin_port = 3306;
sock_addr_serv.sin_addr.s_addr = inet_addr("127.0.0.1");

// connecting to server
socklen_t len = sizeof(sock_addr_serv);
if (connect(serv_fd,(struct sockaddr *)&sock_addr_serv,len)==-1)
{
	perror("connect error");
	exit(1);
}

while(1)
{
	transact_with_server(serv_fd,argc,argv);
	
}


close(serv_fd);

}










