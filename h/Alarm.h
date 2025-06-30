#ifndef ALARM_H
#define ALARM_H
#include"Filter_Signal.h"
#include"freq_period.h"
#include <fstream>
#include <ostream>
#include <iostream>
void Freq_Alarm_List(Freq_Peri_List **Head, double Over_Freq, double Under_Freq);
void Volt_Curr_Alarm_List(Read_data_List **Head, double max_c, double max_v,const string path);
#endif // ALARM_H

