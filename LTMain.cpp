#include<iostream>
//#include<"LT.cpp">
//#include<"LT.h">
#include<istream>
#include<fstream>
#include<string.h>
using namespace std;

int main(char argc,char *argv[])
{
	
	
	if(argc==1)

	{
			     int f = 0; // 0 1 2
    	while(1)
    	{

		int count;
	      //  int flag=0;
		string user,pass,u,p;
		system("cls");
		cout<<"please enter the following details"<<endl;
		cout<<"USERNAME :";
		cin>>user;
		cout<<"PASSWORD :";
		cin>>pass;

		ifstream input("database.txt");
	       	 while(input>>u>>p)
		{
		        if(u==user && p==pass)
		        {
		                count=1;
		                system("cls");
		        }
		}
		input.close();
		if(count==1)
		{
		        cout<<"\nHello "<<user<<"\nLOGIN SUCESS\nWe're glad that you're here.\nThanks for logging in\n";
		        cin.get();
		        cin.get();
		        main();
		}
		else
		{


		   cout<<"\nLOGIN ERROR\nPlease check your username and password\n"<<endl;
			   //login();
		}

	       if(f==2)
	       {
		   cout<<"you have reached the maximum limit";
		   break;
	       }
		 //break;
	       else
		f++;
	}
}
}
