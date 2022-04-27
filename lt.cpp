#include"lt.h"
#include<iostream>
#include<istream>
#include<fstream>
#include<string.h>
#include<map>
using namespace std;
void registr(string reguser,string regpass)
{
     ofstream reg("/home/manohar/project/users.txt",ios::app);
     reg<<reguser<<' '<<regpass<<endl;
     reg.close();
}
bool loginValidate(string u,string p)
{
    /* ifstream fin;
     fin.open("hindi.txt");
     string line;
     string key;
     string value;
     map<string,string>params;
     while(fin>>key>>value)
     {
          params[key]=value;
     }
     map<string,string>::iterator itr;
     fin.close();
     if(params.count(u)==0&& params.count(p)==0)
        return false;
     else
        return true;
     */
     int count;
     string uname,pass;
     ifstream input("/home/manohar/project/users.txt");
     while(input>>uname>>pass)
     {
	     if(u==uname && p==pass)
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
     std::ofstream outfile;
     outfile.open("/home/manohar/project/users.txt",std::ios_base::app);
     cout<<"adding"<<file<<endl;
     return true;
 }
 bool remove(string file)
 {
/*      if(remove("hindi.txt")!=0)
      { 
       perror("error deleting file");
      }
      else
      { 
       cout<<"removing ...."<<file<<endl;
      }*/
      int status;
      int fd=status=remove(file);
      if(status==0)
      return true;
      else
     return false;
 } 
 bool update(string s1,string s2,string file)
 { 
       
      cout<<"updating "<<file<<endl;
      return true;
  }             
