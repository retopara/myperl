#ifndef ASSEMBLY_H
#define ASSEMBLY_H

#include <string>
using namespace std;

void write_main(const double *value, const string orig, const string dest);
void write_target(const double *value, const string orig, const string dest);
void write_replica(const double *value, const string orig, const string dest);

#endif
