#ifndef INTERFACE_LIST_H
#define INTERFACE_LIST_H
#include <iostream>
#include <string>
#include "Read_data.h"
#include "Filter_Signal.h"
#include "freq_period.h"
#include "Alarm.h"
#include "Calc_Stats_Periods.h"
#include "Calc_Energy_Avg-Power_RMS.h"
#define PI 3.14159
using namespace std;
void user_interface_List();
void load1_List();  // Heater
void load2_List();  // Refrigerator
void load3_List();  // Washing Machine
void load4_List();  // Air Conditioner
void total_List();  // Total Home

#endif // INTERFACE_LIST_H
