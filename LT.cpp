#include "LT.h"
#include<iostream>
#include<istream>
#include<fstream>
#include<string.h>
#include<map>
using namespace std;



void registr(char reguser,char regpass)
{

	string reguser,regpass; //regname,regmobile,regemail,regaddress;
        system("cls");
        cout<<"Enter the username :";
        cin>>reguser;
        cout<<"\nEnter the password :";
        cin>>regpass;
        /*
        cout<<"\nEnter the name :";
        cin>>regname;
        cout<<"\nEnter the mobile no :";
        cin>>regmobile;
        cout<<"\nEnter the email :";
        cin>>regemail;
        cout<<"\nEnter the address :";
        cin>>regaddress;
        */
        
        ofstream reg("database.txt",ios::app);
        
        
        reg<<reguser<<' '<<regpass<<endl;//' '<<regname<<' '<<regmobile<<' '<<regemail<<' '<<regaddress<< 
        
        system("cls");
        cout<<"\nRegistration Sucessful\n";
        
		
}


void login(string u,string p)
{
     
    ifstream fin;
    //ofstream fout;
    fin.open("database.txt");

   // string line;
    string key;
    string value;

	map <string, string> params;
	while ( fin >>key >>value ) {
    	params[key] = value; // input them into the map
}

    	map<string,string>::iterator itr;
    	if(params.count(u)==0 && params.count(p)==0)
        cout<<"Erorr in login"<<endl;
   else
   {

       cout<<"Welcome"<<endl;
   }



fin.close();
//fout.close();
}


void add(char)
{
}
void display()
{
	 		int ex=0;
                        string searchword,sw;
                        cout<<"\nEnter the word :";
                        cin>>searchword;
                        
                        ifstream searchw("ds.txt");
                        while(searchw>>sw)
                        {
                                if(sw==searchword)
                                {
                                        ex=1;
                                }
                        }
                        searchw.close();
                        if(ex==1)
                        {
                                
                                cout<<"\nYour word is :"<<sw;
                                cin.get();
                                cin.get();
                                system("cls");
                                
                        }
                        else
                        {
                                cout<<"\nSorry, Your searching word is not found in our server\n";
                                
                                cin.get();
                                cin.get();
                                
                        }
                        
}
void dlt(char)
{
}
void update(char,char)
{
}
void translateWord(char,char)
{
}


