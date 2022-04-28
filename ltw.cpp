#include "ltw.h"
#include<iostream>
#include<istream>
#include<fstream>
#include<string.h>
#include<map>
#include<stdio.h>
#include "ltw.h"
using namespace std;

bool searchword(string s)
{
	    	ifstream fin;

	    	fin.open("hindi.txt");
	    	string key,value;

		map <string, string> params;
		while ( fin >> key >> value )
		{
	    		params[key] = value; // input them into the map
		}
	    	map<string,string>::iterator itr;
	    	itr=params.find(s);


	    	if(params.count(s)==0)
	       	cout<<"NO RESULT FOUND";

	    	else
	    	cout<<itr->first<<" " <<itr->second;




	    	fin.close();

    		return true;
}


