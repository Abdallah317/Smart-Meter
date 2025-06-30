#include "Calc_Stats_Periods.h"
void Calc_Stats_Periods(Freq_Peri_List **Freq_Head,double Tsam)
{
    double sum_v=0,sum_i=0,sum_iv=0,Irms=0,Vrms=0,Avg_Power=0,pf=0;
    Freq_Peri_List *temp_Freq=*Freq_Head;
    Read_data_List *temp_Data=NULL;
    while(temp_Freq!=NULL)
    {
        sum_v=0; sum_i=0; sum_iv=0;
        temp_Data=temp_Freq->Start_Node;
        while(temp_Data->Prev!=temp_Freq->End_Node)
        {
            sum_v+=temp_Data->voltage_mag_filter*temp_Data->voltage_mag_filter;
            sum_i+=temp_Data->current_mag_filter * temp_Data->current_mag_filter;
            sum_iv+=temp_Data->voltage_mag_filter * temp_Data->current_mag_filter;
            temp_Data=temp_Data->Next;
        }
        Irms=sqrt(Tsam*sum_i/(temp_Freq->period));
        Vrms=sqrt(Tsam*sum_v/(temp_Freq->period));
        Avg_Power=(Tsam*sum_iv/(temp_Freq->period));
        pf=(Avg_Power)/(Vrms*Irms);
        cout << "==========================================\n";
        cout << "Frequency     : " << temp_Freq->frequency << " Hz" << endl;
        cout << "Irms          : " << Irms << " A" << endl;
        cout << "Vrms          : " << Vrms << " V" << endl;
        cout << "Average Power : " << Avg_Power << " W" << endl;
        cout << "Power Factor  : " << pf << endl;
        cout << "==========================================\n";

        temp_Freq=temp_Freq->Next;
    }
}
