#include "lt.h"
#include<iostream>
#include<istream>
#include<fstream>
#include<string.h>
#include<map>
#include<stdio.h>
using namespace std;



void registr(string reguser,string regpass)
{
        ofstream reg("/home/translate/users.txt",ios::app);
    
        reg<<reguser<<' '<<regpass<<endl;
      	reg.close();	
}


bool loginValidate(string user,string pass)
{
     

	int count;
        string u,p;
        ifstream input("/home/translate/users.txt");
       	 while(input>>u>>p)
        {
                if(u==user && p==pass)
                {
                        count=1;

                }
        }
        input.close();
        if(count==1)
        {
            
                return true;

        }
        else
        {

            
          	return false;
        }



     
}

	

bool add(string file)
{
	/*
	int fd=open("file","r");
	char targetfile[30];
	strcpy(targetfile,"\home\translate\");
	strcat(targetfile,file.c_str());
	int fd2=open(targetfile,"w");
	return true;
	*/
	return true;
}


bool remove(string file)
{
	    int status;
	    	int fd=
	    
	    
	    status = remove(file);
	    if(status==0)
		return true;
	    else
		return false;
	    
}


bool update(string s1,string s2,string file)
{
	cout << "updating  " << file << endl;
	return true;
}
