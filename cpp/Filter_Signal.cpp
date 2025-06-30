#include "Filter_Signal.h"
using namespace std;
void filtering_list(Read_data_List *Head, double W, double T)
{
    Head->current_mag_filter=Head->current_mag;
    Head->voltage_mag_filter=Head->voltage_mag;
    Head=Head->Next;
    while(Head!=NULL)
    {
        Head->current_mag_filter=(((Head->Prev)->current_mag_filter)+(W*T*(Head->current_mag)))/(1+(W*T));
        Head->voltage_mag_filter=(((Head->Prev)->voltage_mag_filter)+(W*T*(Head->voltage_mag)))/(1+(W*T));
        Head=Head->Next;
    }

}
/*For Printing Filtered Data in csv file*/
/*void filtering_list(Read_data_List *Head, double W, double T, const string &filename)
{
    ofstream outfile(filename);
    if (!outfile.is_open())
    {
        cout<< "Error opening file!" <<endl;
        return;
    }

    // Write CSV header
    outfile << "time,voltage_mag_filter,current_mag_filter" << endl;

    if (Head == NULL)
    {
        outfile.close();
        return;
    }

    Head->current_mag_filter = Head->current_mag;
    Head->voltage_mag_filter = Head->voltage_mag;
    outfile << Head->time << "," << Head->voltage_mag_filter << "," << Head->current_mag_filter << endl;

    Head = Head->Next;

    while (Head != NULL)
    {
        Head->current_mag_filter = (((Head->Prev)->current_mag_filter) + (W * T * (Head->current_mag))) / (1 + (W * T));
        Head->voltage_mag_filter = (((Head->Prev)->voltage_mag_filter) + (W * T * (Head->voltage_mag))) / (1 + (W * T));

        outfile << Head->time << "," << Head->voltage_mag_filter << "," << Head->current_mag_filter << endl;

        Head = Head->Next;
    }

    outfile.close();
}*/

