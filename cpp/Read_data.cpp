#include "Read_data.h"
using namespace std;
void reading_list(Read_data_List **data_Head,Read_data_List **data_Tail, string s1, int List_size,int m)
{
    string time_s, volt_s, curr_s;
    ifstream data_file;
    data_file.open(s1);
    if(data_file.is_open())
    {
        cout<<"Opened Successfully !!"<<endl;
    }
    else
    {
        cout<<"Failed to open this file !!"<<endl;
        return;
    }
    int i=0;
    if(m==2)
    {
    for(i=0;i<List_size;i++)
    {
        getline(data_file, time_s, ',');
        getline(data_file, volt_s, ',');
        getline(data_file, curr_s, '\n');
        Insert_Node_At_End(data_Head,data_Tail,stod(time_s),stod(volt_s),stod(curr_s));
    }

    }

    else if(m==1) /*for total_file only !*/
    {
        for(i=0;i<List_size;i++){
        getline(data_file, volt_s, ',');
        getline(data_file, curr_s, '\n');
        Insert_Node_At_End(data_Head,data_Tail,i*0.001,stod(volt_s),stod(curr_s));
        }
    }
}
void Insert_Node_At_End(Read_data_List **Head,Read_data_List **Tail,double time,double volt,double current)
{
    Read_data_List *temp=new Read_data_List;
    if(temp==NULL)
    {
        printf("Can't allocate this space !\n");
    }
    else
    {
        temp->time=time;
        temp->voltage_mag=volt;
        temp->current_mag=current;
        temp->Next=NULL;
        if(*Head==NULL)
        {//empty list
            temp->Prev=NULL;
            *Head=temp;
            *Tail=temp;
        }
        else
        {
            temp->Prev=*Tail;
           (*Tail)->Next=temp;
           *Tail=temp;
        }
    }
}
void Insert_Node_At_End_Freq(Freq_Peri_List **Head,Freq_Peri_List **Tail)
{
    Freq_Peri_List *temp=new Freq_Peri_List;
    if(temp==NULL)
    {
        printf("Can't allocate this space !\n");
    }
    else
    {
        temp->Next=NULL;
        if(*Head==NULL)
        {//empty list
            temp->Prev=NULL;
            *Head=temp;
            *Tail=temp;
        }
        else
         {
            (*Tail)->Next=temp;
            temp->Prev=(*Tail);
            *(Tail)=temp;
        }
    }
}
void Delete_Node_At_End_Freq(Freq_Peri_List **Tail)
{
    if(*Tail==NULL)
    {
     cout<<"empty list can't delete node at end !!"<<endl;
     return;
    }
    if((*Tail)->Prev==NULL)
    {
        //one node
        delete *Tail;
        *Tail=NULL;
        return;
    }
    ((*Tail)->Prev)->Next=NULL;
    (*Tail)->Prev=NULL;
    Freq_Peri_List *Node_To_Delete=*Tail;
    *Tail=(*Tail)->Prev;
    delete Node_To_Delete;
}
