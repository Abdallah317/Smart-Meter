#ifndef ALARM_H
#define ALARM_H
#include"Filter_Signal.h"
#include"freq_period.h"
#include <fstream>
#include <ostream>
#include <iostream>
void Alarm(Filter_Signal s[], pp *f,int m, double Tsampling,int max_c,int max_v,int over_freq,int under_freq );
void Freq_Alarm_List(Freq_Peri_List **Head, double Over_Freq, double Under_Freq);
void Volt_Curr_Alarm_List(Read_data_List **Head, double max_c, double max_v,const string path);
#endif // ALARM_H

