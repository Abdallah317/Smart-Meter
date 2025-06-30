#include"Alarm.h"
using namespace std;
void Alarm(Filter_Signal s[], pp *f,int m, double Tsampling,int max_c,int max_v,int over_freq,int under_freq ) {
    int i;
    int j;
    for(i=0;i<m;i++)
    {
        for(j=f[i].start;j<=f[i].end;j++)
        {
            if(s[j].current_mag_filtered>max_c)
            {
                double x=s[j].time_filter;
                if(s[j+1].current_mag_filtered<=max_c)
                    cout<<"the current exceeding maximum at time ="<<x<<" sec"<<endl;
                else
                {
                    while(s[j].current_mag_filtered>max_c)
                        j++;
                    cout<<"the current exceeding maximum from t="<<x<<" sec"<<" to t= "<<s[j-1].time_filter<<" sec ,interval ="<<s[j-1].time_filter-x<<" sec"<<endl;

                }
            }
        }
    }
    for(i=0;i<m;i++) //m is the number of the periods
    {
        for(j=f[i].start;j<=f[i].end;j++)
        {
            if(s[j].voltage_mag_filtered>max_v)
            {
                double y=s[j].time_filter;
                if(s[j+1].voltage_mag_filtered<=max_v)
                    cout<<"the voltage exceeding maximum at time ="<<y<<" sec"<<endl;
                else
                {
                    while(s[j].voltage_mag_filtered>max_v)
                        j++;
                    cout<<"the voltage exceeding maximum from t="<<y<<" sec"<<" to t= "<<s[j-1].time_filter<<" sec ,interval ="<<s[j-1].time_filter-y<<" sec"<<endl;

                }
            }
        }
    }
for( i=0;i<m;i++)
{
if(f[i].frequncy >over_freq)
cout<<"Over Frequency from "<<f[i].start *Tsampling<<" sec to "<<f[i].end *Tsampling<<" sec"<<endl;
if(f[i].frequncy<under_freq)
cout<<"Under Frequency from "<<f[i].start *Tsampling<<" sec to "<<f[i].end *Tsampling<<" sec"<<endl;
}
    /*for (i = 0; i < size; i++) // this was an old edit (alarm on all the points in the filtered signal)
        if (s[i].current_mag_filtered > max_c)
        {
            double x = s[i].time_filter;
            if (s[i+1].current_mag_filtered <=max_c)
                cout << "the current exceeding maximum current at time = " << x << " sec" << endl;
            else
            {
                while (s[i].current_mag_filtered > max_c)
                    i++;
                cout << "the current exceeding maximum current from t= " << x << " sec" << " to t= " << s[i-1].time_filter << " sec ,interval =  " << s[i-1].time_filter- x << "sec" << endl;
            }
        }
    for (i = 0; i < size; i++)
        if (s[i].voltage_mag_filtered > max_v)
        {
            double y = s[i].time_filter;
            if (s[i+1].voltage_mag_filtered <= max_v)
                cout << "the voltage exceeding maximum voltage at time = " << y << " sec" << endl;
            else
            {
                while (s[i].voltage_mag_filtered > max_v)
                    i++;
                cout << "the voltage exceeding maximum voltage from t= " << y << " sec " << "to t= " << s[i-1].time_filter << " sec ,interval =  " << s[i-1].time_filter - y << "sec" << endl;
            }
        }*/

}
void Freq_Alarm_List(Freq_Peri_List **Head, double Over_Freq, double Under_Freq)
{
    Freq_Peri_List *temp = *Head, *temp_delete = NULL, *temp_next = NULL;
    cout << "===== Frequency Alarm Report =====" << endl;
    while (temp != NULL)
    {
        if (temp->frequency >= Over_Freq)
        {
            cout << "[ALERT] Over-frequency event detected" << endl;
            cout << " - Time Interval: " << temp->Start_Node->time << " s to " << temp->End_Node->time << " s" << endl;
            cout << " - Frequency: " << temp->frequency << " Hz (Threshold: " << Over_Freq << " Hz)" << endl;
            cout << "---------------------------------------" << endl;

            temp_delete = temp;
            temp_next = temp->Next;
            if (temp->Next == NULL)
            {
                temp->Prev->Next = NULL;
            }
            else if (temp->Prev == NULL)
            {
                temp->Next->Prev = NULL;
                *Head = temp->Next;
            }
            else
            {
                temp->Prev->Next = temp->Next;
                temp->Next->Prev = temp->Prev;
            }
            temp = temp_next;
            free(temp_delete);
            continue;
        }
        else if (temp->frequency <= Under_Freq)
        {
            cout << "[ALERT] Under-frequency event detected" << endl;
            cout << " - Time Interval: " << temp->Start_Node->time << " s to " << temp->End_Node->time << " s" << endl;
            cout << " - Frequency: " << temp->frequency << " Hz (Threshold: " << Under_Freq << " Hz)" << endl;
            cout << "---------------------------------------" << endl;

            temp_delete = temp;
            temp_next = temp->Next;
            if (temp->Next == NULL)
            {
                temp->Prev->Next = NULL;
            }
            else if (temp->Prev == NULL)
            {
                temp->Next->Prev = NULL;
                *Head = temp->Next;
            }
            else
            {
                temp->Prev->Next = temp->Next;
                temp->Next->Prev = temp->Prev;
            }
            temp = temp_next;
            free(temp_delete);
            continue;
        }
        temp = temp->Next;
    }
    cout << "===== Frequency Alarm Check Complete =====" << endl;
}
void Volt_Curr_Alarm_List(Read_data_List **Head, double max_c, double max_v,const string path)
{
    Read_data_List *temp = *Head;
    double Start = 0, End = 0;
    ofstream outfile(path);
    cout << "===== Voltage Alarm Report =====" << endl;
    outfile<<","<<"from"<<","<<"to"<<endl;
    while (temp != NULL)
    {
        if (temp->voltage_mag_filter > max_v)
        {
            Start = temp->time;
            while (temp != NULL && temp->voltage_mag_filter > max_v)
            {
                temp = temp->Next;
            }
            if (temp != NULL)
            {
                End = temp->Prev->time;
                if(End-Start>0.001)
                outfile << "Voltage exceeded " <<","<< Start<<","<<End<< endl;
            }
        }
        else
        {
            temp = temp->Next;
        }
    }

    cout << "======= Voltage Alarm Check Complete =======" << endl;

    temp = *Head;
    cout << "===== Current Alarm Report =====" << endl;
    while (temp != NULL)
    {
        if (temp->current_mag_filter > max_c)
        {
            Start = temp->time;
            while (temp != NULL && temp->current_mag_filter > max_c)
            {
                temp = temp->Next;
            }
            if (temp != NULL)
            {
                End = temp->Prev->time;
                if(End-Start>0.001)
                outfile << "Current exceeded " <<","<<Start<<","<<End<< endl;
            }
        }
        else
        {
            temp = temp->Next;
        }
    }

    cout << "======= Current Alarm Check Complete =======" << endl;
    cout<<"Current,Voltage Alarms Saved in csv file in loacation : "<<path<<endl;
}



