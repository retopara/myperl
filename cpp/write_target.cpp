#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "layout.h"

using namespace std;

void write_target(const double *value, const string orig, const string dest)
{
	//readin parameters for target function
	int	
		dim, //spin only have up or down, spin 1/2 system, dim = 2
		schnum, //schmidt number of decomposition is 8
		N, //the length of spin chain is 2^N
		Nrelax, //the number of relaxation sweeps
		Nsample, //the number of sweeps when calculating energy.
		L, //the length of spin chain
		Nsample_inc, //the increment of Nsample per recursion.
		nx; //the number of variables
	double
		thr, //thr, threshold of esite error
		h; //the strength of transverse field

	//read in input file
	string fname = orig + "/input/target.input";

	string str;
	ifstream ifs;
  ifs.open(fname.c_str());
	if(!ifs)
	{
		cerr << "\nCannot find the file: " << fname.c_str() << endl;
		abort();
	}

	ifs >> dim;	getline(ifs, str);
	ifs >> schnum;	getline(ifs, str);
	ifs >> N;	getline(ifs, str);
	ifs >> Nrelax;	getline(ifs, str);
	ifs >> Nsample;	getline(ifs, str);
	ifs >> h;	getline(ifs, str);
	ifs >> thr;	getline(ifs, str);
	ifs >> Nsample_inc;	getline(ifs, str);
	ifs.close();
	//end read in
	
	//write file in destination folder
	fname = dest + "/input/target.input";
	cout << fname.c_str() << endl;

	ofstream ofs;
	ofs.open(fname.c_str());
	if(!ofs)
	{
		cerr << "\ncan't open file " << fname.c_str() << endl;
		abort();
	}

	//alter parameter for each folder
	ofs << value[0] << "\t\t\t\t\t//dim, spin only have up or down, spin 1/2 system, dim = 2" << endl;
	ofs << value[1] << "\t\t\t\t\t//schnum, schmidt number of decomposition is 8" << endl;
	ofs << value[2] << "\t\t\t\t\t//N, the length of spin chain is 2^N" << endl;
	ofs << value[3] << "\t\t\t\t\t//Nchain, the number of MC chains in sampling" << endl;
	ofs << value[4] << "\t\t\t\t\t//Nrelax, the number of relaxation sweeps" << endl;
	ofs << value[5] << "\t\t\t\t\t//Nsample, the number of sweeps when calculating energy." << endl;
	ofs << value[6] << "\t\t\t\t\t//h, the strength of transverse field" << endl;
//  ofs << value[6] << "\t\t\t\t\t//thr, threshold of esite error" << endl;
	ofs << value[7] << "\t\t\t\t\t//Nsample_inc, the increment of Nsample per recursion." << endl;
	ofs << value[8] << "\t\t\t\t\t//probmin, the lowest probability allowed to appear in a Markov chain" << endl << endl;
	ofs << "\n//the input for target function" << endl;
	ofs.close();
}
