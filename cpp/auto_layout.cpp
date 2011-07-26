/**************************************************************************************
 *		My First C++ Program!
 *
 *		FILE NAME:	make_fname.cpp
 *
 *		PURPOSE:		Automatically generates datafile with same name to different folders,
 *								using c++ to call system commands.
 *
 **************************************************************************************/

#include <cstdlib>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include "layout.h"

using namespace std;

int main(int argc, char **argv)
{
	string 
		orig, //name of origin folder
		dest; //name of destination folder
	int
		numdest, //the number of run folder
		numpara; //the number of parameter lists
	double
		value[100][20];

	//readin parameters for auto layout function 

	string str;
	ifstream ifs;
	ifs.open("./layout.input");
	if(!ifs)
	{
		cerr << "\nCannot find the file: ./layout.input" << endl;
		abort();
	}
	
	ifs >> orig;
	getline(ifs, str);
	ifs >> dest;
	getline(ifs, str);
	ifs >> numdest;
	getline(ifs, str);
	ifs >> numpara;
	getline(ifs, str);

	cout << "orig= " << orig << endl;
	cout << "dest= " << dest << endl;
	cout << "numdest= " << numdest << endl;
	cout << "numpara= " << numpara << endl;

	//readin values for parameter
	getline(ifs, str);
	getline(ifs, str);
	cout << "values are:" << endl;
	for(int i=0; i<numdest; i++)
	{
		for(int j=0; j<numpara; j++)
		{
			ifs >> value[i][j];
			cout << "\t" << value[i][j];
		}
		cout << endl;
	}
	ifs.close();
	//end readin
	
	//auto layout commands
	ostringstream dest_fname, command;
	for(int i=0; i<numdest; i++)
	{
		dest_fname.str("");
		cout << "===================================================" << endl;

		dest_fname << dest << "_" << (i+1);
		command << "test -d " << dest_fname.str().c_str() << " || cp -r "<< orig.c_str() << " " << dest_fname.str().c_str() << endl; 
		cout << command.str().c_str();
		system(command.str().c_str());
		command.str("");

		command << "rm -r " << dest_fname.str().c_str() << "/input" << endl;
		cout << command.str().c_str();
		system(command.str().c_str());
		command.str("");

		command << "mkdir " << dest_fname.str().c_str() << "/input" << endl;
		cout << command.str().c_str();
		system(command.str().c_str());
		command.str("");

//    pbs(dest.str());
		write_target(value[i], orig, dest_fname.str());
		write_main(value[i], orig, dest_fname.str());
		write_replica(value[i], orig, dest_fname.str());
	}
}
