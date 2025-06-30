#include"Alarm.h"
using namespace std;
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



