#ifndef FREQ_PERIOD_H
#define FREQ_PERIOD_H
#include <cmath>
#include <iostream>
#include "Filter_Signal.h"
struct pp {
	double start;
	double end;
	double period;
	double frequncy;
};
pp* delete_1(int idx,int &size11,pp *arr);
pp* Freq_peri(Filter_Signal f[], int size1, double Tsampling,int &period_no);
Freq_Peri_List * Freq_Peri_List_Fun(Read_data_List **Head,double Tsam);
void Freq_Peri_Sorting_List(Freq_Peri_List **Head);
void Get_Unique_Elements_List(Freq_Peri_List **Head,double Tsam);
void Get_Unique_Elements_List_1(Freq_Peri_List **Head);
#endif // FREQ_PERIOD_H
