#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include "layout.h"

using namespace std;

void write_main(const double *value, const string orig, const string dest)
{
	//readin parameters for target function
	int	
		nrec, //the times of temperature adjustment(recursion)
		nexch, //the times of temperature exchange
		nswp, //the times of local MC
		nequi1, //the times of relaxation at the beginning.
		nequi2; //the times of relaxation after one temperature adjustment.
	double
		bmin, //the min beta(highest temperature)
		bmax, //the max beta(lowest temperature)
		tol; //the tolerance of result

	//read in input file
	string fname = orig + "/input/main.input";

	string str;
	ifstream ifs(fname.c_str());
	if(!ifs)
	{
		cerr << "\nCannot find the file: " << fname.c_str() << endl;
		abort();
	}

	ifs >> nrec;	getline(ifs, str);
	ifs >> nexch;	getline(ifs, str);
	ifs >> nswp;	getline(ifs, str);
	ifs >> nequi1;	getline(ifs, str);
	ifs >> nequi2;	getline(ifs, str);
	ifs >> bmin;	getline(ifs, str);
	ifs >> bmax;	getline(ifs, str);
	ifs >> tol;	getline(ifs, str);
	ifs.close();
	//end read in
	
	//write file in destination folder
	fname = dest + "/input/main.input";
	cout << fname.c_str() << endl;

	ofstream ofs;
	ofs.open(fname.c_str());
	if(!ofs)
	{
		cerr << "\ncan't open file " << fname.c_str() << endl;
		abort();
	}

	ofs << nrec << "\t\t\t\t\t//nrec, the times of temperature adjustment(recursion)" << endl;
	ofs << nexch << "\t\t\t\t\t//nexch, the times of temperature exchange" << endl;
	ofs << nswp << "\t\t\t\t\t//nswp, the times of local MC" << endl;
	ofs << nequi1 << "\t\t\t\t\t//nequi1, the times of relaxation at the beginning." << endl;
	ofs << nequi2 << "\t\t\t\t\t//nequi2, the times of relaxation after one temperature adjustment." << endl;
	ofs << bmin << "\t\t\t\t\t//bmin, the min beta(highest temperature)" << endl;
	ofs << bmax << "\t\t\t\t\t//bmax, the max beta(lowest temperature)"  << endl;
	ofs << tol << "\t\t\t\t\t//tol, the tolerance of result" << endl << endl;
	ofs << "//input for main()" << endl;
	ofs.close();
}
