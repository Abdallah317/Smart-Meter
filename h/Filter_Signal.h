#ifndef FILTER_SIGNAL_H
#define FILTER_SIGNAL_H
#include <string>
#include <iostream>
#include <fstream>
#include "Read_data.h"
using namespace std;
struct Filter_Signal
{
    double current_mag_filtered;
    double voltage_mag_filtered;
    double time_filter;
};
void filtering_list(Read_data_List *Head,double W, double T);
//void filtering_list(Read_data_List *Head, double W, double T, const string &filename); /*for printing*/
#endif // FILTER_SIGNAL_H
