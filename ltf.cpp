#include "LT.h"
#include<iostream>
#include<istream>
#include<fstream>
#include<string.h>
#include<map>
using namespace std;



void registr(string reguser,string regpass)
{
        ofstream reg("/home/translate/users.txt",ios::app);
    
        reg<<reguser<<' '<<regpass<<endl;//' '<<regname<<' '<<regmobile<<' '<<regemail<<' '<<regaddress<< 
      	reg.close();	
}


bool loginValidate(string u,string p)
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
	cout << "adding " << file << endl;
	return true;
	
}


bool remove(string file)
{
	cout << "removing ..." << file << endl;
	return true;
}


bool update(string s1,string s2,string file)
{
	cout << "updating  " << file << endl;
	return true;
}



