#include "interface_List.h"
void user_interface_List() {
    int choice;
    while (true) {
        cout << "\n========== Smart Meter Interface ==========" << endl;
        cout << "Please choose a load to analyze:\n";
        cout << "1. Heater (Load 1)\n";
        cout << "2. Refrigerator (Load 2)\n";
        cout << "3. Washing Machine (Load 3)\n";
        cout << "4. Air Conditioner (Load 4)\n";
        cout << "5. Total Home\n";
        cout << "0. Exit\n";
        cout << "===========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                load1_List();
                break;
            case 2:
                load2_List();
                break;
            case 3:
                load3_List();
                break;
            case 4:
                load4_List();
                break;
            case 5:
                total_List();
                break;
            case 0:
                cout << "Exiting... Goodbye!\n";
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

        cout << "\n-------------------------------------------\n";
    }
}

void load1_List() {
    Read_data_List *Head = NULL, *Tail = NULL;
    double max_c=10,max_v=400;
    reading_list(&Head, &Tail, "C:/Users/PC/Desktop/Smart_Meter_Edits/project files/Load1 (1).csv", 500001, 2);
    /*For Printing Filtered Data in csv file*/
    //filtering_list(Head, 2 * PI * 500, 0.0001,"C:/Users/PC/Desktop/Smart_Meter_Edits/csv output files/Load1_Filtered.csv");
    filtering_list(Head, 2 * PI * 500, 0.0001);
    Freq_Peri_List *Freq_Head = Freq_Peri_List_Fun(&Head, 0.0001);
    cout<<"==================Alarm Start====================="<<endl;
    Freq_Alarm_List(&Freq_Head,52,48);
    Volt_Curr_Alarm_List(&Head,max_c,max_v,"C:/Users/PC/Desktop/Smart_Meter_Edits/Alarm_CSV_Files/Load1_Alarm.csv");
    cout<<"==================Alarm End======================="<<endl;
    cout << "================== Per-Frequency Period Stats =====================" << endl;
    cout << "Data computed over detected ON-frequency periods: Power Factor, Average Power, RMS Current, RMS Voltage" << endl;
    Calc_Stats_Periods(&Freq_Head, 0.0001);
    cout << "==================Power Factor Calculation End=======================" << endl;
    cout << "Heater:" << endl;
    double Rms_v = 0, Rms_i = 0,Energy=0,Avg_Power=0;
    computeEnergyAvgPowerRMS(&Head, 500001, &Rms_v, &Rms_i,&Energy,&Avg_Power,0.0001);
    cout << "Combined RMS Voltage : " << Rms_v << " V\nCombined RMS Current : " << Rms_i << " A" << endl;
    cout<<"Combined Average Power : "<<Avg_Power<<" W\nCombined Energy : "<<Energy<<" KWH\nMonthly Cost : "<<cost_calc(Energy)<<" EGP"<<endl;
}

void load2_List() {
    Read_data_List *Head = NULL, *Tail = NULL;
    double max_c=15,max_v=400;
    reading_list(&Head, &Tail, "C:/Users/PC/Desktop/Smart_Meter_Edits/project files/Load2.csv", 500001, 2);
    /*For Printing Filtered Data in csv file*/
    //filtering_list(Head, 2 * PI * 500, 0.0001,"C:/Users/PC/Desktop/Smart_Meter_Edits/csv output files/Load2_Filtered.csv");
    filtering_list(Head, 2 * PI * 500, 0.0001);
    Freq_Peri_List *Freq_Head = Freq_Peri_List_Fun(&Head, 0.0001);
    cout<<"==================Alarm Start====================="<<endl;
    Freq_Alarm_List(&Freq_Head,52,48);
    Volt_Curr_Alarm_List(&Head,max_c,max_v,"C:/Users/PC/Desktop/Smart_Meter_Edits/Alarm_CSV_Files/Load2_Alarm.csv");
    cout<<"==================Alarm End======================="<<endl;
    cout << "================== Per-Frequency Period Stats =====================" << endl;
    cout << "Data computed over detected ON-frequency periods: Power Factor, Average Power, RMS Current, RMS Voltage : " << endl;
    Calc_Stats_Periods(&Freq_Head, 0.0001);
    cout << "==================Power Factor Calculation End=======================" << endl;
    cout << "Refrigerator:" << endl;
    double Rms_v = 0, Rms_i = 0,Energy=0,Avg_Power=0;
    computeEnergyAvgPowerRMS(&Head, 500001, &Rms_v, &Rms_i,&Energy,&Avg_Power,0.0001);
    cout << "Combined RMS Voltage : " << Rms_v << " V\nCombined RMS Current : " << Rms_i << " A" << endl;
    cout<<"Combined Average Power : "<<Avg_Power<<" W\nCombined Energy : "<<Energy<<" KWH\nMonthly Cost : "<<cost_calc(Energy)<<" EGP"<<endl;
}

void load3_List() {
    Read_data_List *Head = NULL, *Tail = NULL;
    double max_c=15,max_v=400;
    reading_list(&Head, &Tail, "C:/Users/PC/Desktop/Smart_Meter_Edits/project files/Load3.csv", 500001, 2);
    /*For Printing Filtered Data in csv file*/
    //filtering_list(Head, 2 * PI * 500, 0.0001,"C:/Users/PC/Desktop/Smart_Meter_Edits/csv output files/Load3_Filtered.csv");
    filtering_list(Head, 2 * PI * 500, 0.0001);
    Freq_Peri_List *Freq_Head = Freq_Peri_List_Fun(&Head, 0.0001);
    cout<<"==================Alarm Start====================="<<endl;
    Freq_Alarm_List(&Freq_Head,52,48);
    Volt_Curr_Alarm_List(&Head,max_c,max_v,"C:/Users/PC/Desktop/Smart_Meter_Edits/Alarm_CSV_Files/Load3_Alarm.csv");
    cout<<"==================Alarm End======================="<<endl;
    cout << "Data computed over detected ON-frequency periods: Power Factor, Average Power, RMS Current, RMS Voltage : " << endl;
    Calc_Stats_Periods(&Freq_Head, 0.0001);
    cout << "==================Power Factor Calculation End=======================" << endl;
    cout << "Washing Machine:" << endl;
    double Rms_v = 0, Rms_i = 0,Energy=0,Avg_Power=0;
    computeEnergyAvgPowerRMS(&Head, 500001, &Rms_v, &Rms_i,&Energy,&Avg_Power,0.0001);
    cout << "Combined RMS Voltage : " << Rms_v << " V\nCombined RMS Current : " << Rms_i << " A" << endl;
    cout<<"Combined Average Power : "<<Avg_Power<<" W\nCombined Energy : "<<Energy<<" KWH\nMonthly Cost : "<<cost_calc(Energy)<<" EGP"<<endl;
}

void load4_List() {
    Read_data_List *Head = NULL, *Tail = NULL;
    double max_c=15,max_v=400;
    reading_list(&Head, &Tail, "C:/Users/PC/Desktop/Smart_Meter_Edits/project files/Load4.csv", 500001, 2);
    /*For Printing Filtered Data in csv file*/
    //filtering_list(Head, 2 * PI * 500, 0.0001,"C:/Users/PC/Desktop/Smart_Meter_Edits/csv output files/Load4_Filtered.csv");
    filtering_list(Head, 2 * PI * 500, 0.0001);
    Freq_Peri_List *Freq_Head = Freq_Peri_List_Fun(&Head, 0.0001);
    cout<<"==================Alarm Start====================="<<endl;
    Freq_Alarm_List(&Freq_Head,52,48);
    Volt_Curr_Alarm_List(&Head,max_c,max_v,"C:/Users/PC/Desktop/Smart_Meter_Edits/Alarm_CSV_Files/Load4_Alarm.csv");
    cout<<"==================Alarm End======================="<<endl;
    cout << "Data computed over detected ON-frequency periods: Power Factor, Average Power, RMS Current, RMS Voltage : " << endl;
    Calc_Stats_Periods(&Freq_Head, 0.0001);
    cout << "==================Power Factor Calculation End=======================" << endl;
    cout << "Air Conditioner:" << endl;
    double Rms_v = 0, Rms_i = 0,Energy=0,Avg_Power=0;
    computeEnergyAvgPowerRMS(&Head, 500001, &Rms_v, &Rms_i,&Energy,&Avg_Power,0.0001);
    cout << "Combined RMS Voltage : " << Rms_v << " V\nCombined RMS Current : " << Rms_i << " A" << endl;
    cout<<"Combined Average Power : "<<Avg_Power<<" W\nCombined Energy : "<<Energy<<" KWH\nMonthly Cost : "<<cost_calc(Energy)<<" EGP"<<endl;
}

void total_List() {
    Read_data_List *Head = NULL, *Tail = NULL;
    double max_c=15,max_v=400;
    reading_list(&Head, &Tail, "C:/Users/PC/Desktop/Smart_Meter_Edits/project files/Total (2).csv", 10800000, 1);
    /*For Printing Filtered Data in csv file*/
    //filtering_list(Head, 10000, 0.001,"C:/Users/PC/Desktop/Smart_Meter_Edits/csv output files/Total_Home_Filtered.csv");
    filtering_list(Head, 10000, 0.001);
    Freq_Peri_List *Freq_Head = Freq_Peri_List_Fun(&Head, 0.001);
    cout<<"==================Alarm Start====================="<<endl;
    Freq_Alarm_List(&Freq_Head,52,48);
    Volt_Curr_Alarm_List(&Head,max_c,max_v,"C:/Users/PC/Desktop/Smart_Meter_Edits/Alarm_CSV_Files/Total_Home_Alarm.csv");
    cout<<"==================Alarm End======================="<<endl;
    cout << "Data computed over detected ON-frequency periods: Power Factor, Average Power, RMS Current, RMS Voltage : " << endl;
    Calc_Stats_Periods(&Freq_Head, 0.001);
    cout << "==================Power Factor Calculation End=======================" << endl;
    cout << "Total Home:" << endl;
    double Rms_v=0, Rms_i=0,Energy=0,Avg_Power=0;
    computeEnergyAvgPowerRMS(&Head, 10800000, &Rms_v, &Rms_i,&Energy,&Avg_Power,0.001);
    cout << "Combined RMS Voltage : " << Rms_v << " V\nCombined RMS Current : " << Rms_i << " A" << endl;
    cout<<"Combined Average Power : "<<Avg_Power<<" W\nCombined Energy : "<<Energy<<" KWH\nMonthly Cost : "<<cost_calc(Energy)<<" EGP"<<endl;
}
