#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

void find_minmax(const vector<double>& numbers, double& min, double& max);
void show_histogram_text(vector<size_t> bins);
void make_histogram(const size_t& bin_count, const size_t& number_count, const vector<double>& numbers,vector <size_t>& bins, double& min, double& max );


#endif // HISTOGRAM_H_INCLUDED
