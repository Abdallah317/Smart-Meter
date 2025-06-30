#ifndef READ_DATA_H
#define READ_DATA_H
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
struct Read_data_List
{
    double current_mag;
    double voltage_mag;
    double current_mag_filter;
    double voltage_mag_filter;
    double time;
    Read_data_List *Next;
    Read_data_List *Prev;
};
struct Freq_Peri_List
{   double period;
    double frequency;
    Read_data_List *Start_Node;
    Read_data_List *End_Node;
    Freq_Peri_List *Next;
    Freq_Peri_List *Prev;
};
void reading_list(Read_data_List **data_Head,Read_data_List **data_Tail, string s1, int List_size,int m);
void Insert_Node_At_End(Read_data_List **Head,Read_data_List **Tail,double time,double volt,double current);
void Insert_Node_At_End_Freq(Freq_Peri_List **Head,Freq_Peri_List **Tail);
void Delete_Node_At_End_Freq(Freq_Peri_List **Tail);
#endif // READ_DATA_H
