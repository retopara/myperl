#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include "layout.h"

using namespace std;

void write_replica(const double *value, const string orig, const string dest)
{
	//readin parameters for target function
	int	
		CONVMAX, //CONVMAX
		nscheme; //nscheme, the number of exchange schemes
	long double
		PI; //PI, the value of PI
	double
		sigmainit; //sigmainit, the initial value for sigma.

	//read in input file
	string fname = orig + "/input/replicainit.input";

	string str;
	ifstream ifs(fname.c_str());
	if(!ifs)
	{
		cerr << "\nCannot find the file: " << fname.c_str() << endl;
		abort();
	}

	ifs >> PI; getline(ifs, str);
	ifs >> CONVMAX;	getline(ifs, str);
	ifs >> nscheme;	getline(ifs, str);
	ifs >> sigmainit;	getline(ifs, str);
	ifs.close();
	//end read in
	
	//write file in destination folder
	fname = dest + "/input/replicainit.input";
	cout << fname.c_str() << endl;

	ofstream ofs;
	ofs.open(fname.c_str());
	if(!ofs)
	{
		cerr << "\ncan't open file " << fname.c_str() << endl;
		abort();
	}

	ofs << setprecision(16) << PI << "\t\t\t\t\t//PI, the value of PI" << endl;     
	ofs << setprecision(6);
	ofs << CONVMAX << "\t\t\t\t\t//CONVMAX" << endl;
	ofs << nscheme << "\t\t\t\t\t//nscheme, the number of exchange schemes" << endl;
	ofs << sigmainit << "\t\t\t\t\t//sigmainit, the initial value for sigma." << endl << endl;
	ofs << "//the input for replica exchange initialization" << endl;
	ofs.close();
}
