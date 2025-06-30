#include "Calc_Energy_Avg-Power_RMS.h"
void computeEnergyAvgPowerRMS(Read_data_List **Data_Head, int Size,double *RMS_v,double *RMS_i,double *Energy,double *Avg_Power,double Tsam)
{
    double sum_v=0,sum_i=0,sum_vi=0;
    Read_data_List *ptr=*Data_Head;
    while(ptr!=NULL)
        {
            sum_v+=(ptr->voltage_mag_filter)*(ptr->voltage_mag_filter);
            sum_i+=(ptr->current_mag_filter)*(ptr->current_mag_filter);
            sum_vi+=(ptr->voltage_mag_filter)*(ptr->current_mag_filter);
            ptr=ptr->Next;
        }

    *RMS_v=sqrt(sum_v/Size);
    *RMS_i=sqrt(sum_i/Size);
    *Energy=sum_vi*Tsam*30/(1000*60*60); //KWH
    *Avg_Power=sum_vi/Size;
}
