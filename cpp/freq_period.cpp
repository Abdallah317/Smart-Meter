#include "freq_period.h"
Freq_Peri_List * Freq_Peri_List_Fun(Read_data_List **Head,double Tsam)
{
    Freq_Peri_List *Data_Head=NULL,*Data_Tail=NULL;
    Read_data_List *ptr=*Head;
    int i=0,Start_idx=0,End_idx=0;
    Insert_Node_At_End_Freq(&Data_Head,&Data_Tail);
    Freq_Peri_List *temp=Data_Tail;
    while((ptr!=NULL) && (ptr->Next!=NULL)) //to ensure that ptr->Next is not NULL to access voltage_mag_filter !!
    {
        if(((ptr->voltage_mag_filter)<0)&&((ptr->Next->voltage_mag_filter)>0))
        {
            if(i%2==0)
            {
                Start_idx=(ptr->time)/Tsam;
                temp->Start_Node=ptr;
                //cout<<"Start_Index : "<<Start_idx<<endl;
            }
            else
            {
                End_idx=(ptr->time)/Tsam;
                //cout<<"End_Index : "<<End_idx<<endl;
               // cout<<"Frequency : "<<1/((End_idx-Start_idx)*Tsam)<<endl;
                temp->period=(End_idx-Start_idx)*Tsam;
                temp->frequency=1/(temp->period);
                temp->End_Node=ptr;
                //cout<<"Period : "<<temp->period<<endl;
                Insert_Node_At_End_Freq(&Data_Head,&Data_Tail);
                temp=Data_Tail;
            }
            i++;
        }
        ptr=ptr->Next;
    }
    if(i%2==0)
    {
        //ok
    }
    else
    {
        Delete_Node_At_End_Freq(&Data_Tail);
    }

    /*for printing*//*
    Freq_Peri_Sorting_List(&Data_Head);
    temp=Data_Head;
    while(temp!=NULL)
    {
        cout<<"Period : "<<temp->period<<endl;
        cout<<"Start Node : "<<temp->Start_Node<<endl;
        cout<<"End Node : "<<temp->End_Node<<endl;
        cout<<"=================================="<<endl;
        temp=temp->Next;
    }
    cout<<"=================================="<<endl;
    Get_Unique_Elements_List(&Data_Head,Tsam);
      temp=Data_Head;
    while(temp!=NULL)
    {
        cout<<"Period : "<<temp->period<<endl;
        cout<<"Frequncy : "<<temp->frequency<<endl;
        cout<<"Start Node : "<<temp->Start_Node<<endl;
        cout<<"End Node : "<<temp->End_Node<<endl;
        cout<<"=================================="<<endl;
        temp=temp->Next;
    }*/
    /*Freq_Peri_Sorting_List(&Data_Head);
    Get_Unique_Elements_List(&Data_Head,Tsam);
    return Data_Head;*/
    Freq_Peri_Sorting_List(&Data_Head);
    Get_Unique_Elements_List_1(&Data_Head);
    return Data_Head;
}

void Freq_Peri_Sorting_List(Freq_Peri_List **Head)
{
    if (*Head == NULL)
    {
        return;
    }
    Freq_Peri_List *curr = *Head, *sorted = NULL, *next=NULL, *curr_sorted = NULL;
    while (curr != NULL)
    {
        next=curr->Next;
        if ((sorted == NULL) || (sorted->period > curr->period))
        {
            curr->Next = sorted;
            // if sorted is not empty ,set its 'Prev'
            if (sorted != NULL)
            {
                sorted->Prev = curr;
            }
            // update stored
            sorted = curr;
            sorted->Prev = NULL;
        }
        else
        {
            // pointer to traverse the sorted part
            curr_sorted = sorted;
            // find the correct position to insert
            while ((curr_sorted->Next != NULL) && (curr_sorted->Next->period < curr->period))
            {
                curr_sorted = curr_sorted->Next;
            }
            // insert 'curr' after 'curr_sorted'
            curr->Next = curr_sorted->Next;
            // set 'Prev' if 'curr' is not inserted at end !
            if (curr_sorted->Next != NULL)
            {
                curr_sorted->Next->Prev = curr;
            }
            // set 'next' of 'curr_sorted','Prev' of 'curr'
            curr_sorted->Next = curr;
            curr->Prev = curr_sorted;
        }
        curr = next;
    }
    *Head = sorted;
}
void Get_Unique_Elements_List(Freq_Peri_List **Head, double Tsam)
{
    Freq_Peri_List *curr=*Head, *temp=NULL;
    while (curr->Next!=NULL)
    {
        if (abs(curr->period - curr->Next->period) <= 10 * Tsam)
        {
            // Duplicate detected >>>delete 'curr->Next'
            temp = curr->Next;
            curr->Next = temp->Next;
            if (temp->Next != NULL)
            {
                temp->Next->Prev = curr;
            }
            free(temp);
            //after deletion there is no need to set curr to its next cause one node has deleted so check for the next one !!
        }
        else
        {
            curr = curr->Next; // only move forward if no deletion
        }
    }
}
void Get_Unique_Elements_List_1(Freq_Peri_List **Head)
{
    Freq_Peri_List *curr=*Head, *temp=NULL;
    while (curr->Next!=NULL)
    {
        if (curr->period == curr->Next->period)
        {
            // Duplicate detected >>>delete 'curr->Next'
            temp = curr->Next;
            curr->Next = temp->Next;
            if (temp->Next != NULL)
            {
                temp->Next->Prev = curr;
            }
            free(temp);
            //after deletion there is no need to set curr to its next cause one node has deleted so check for the next one !!
        }
        else
        {
            curr = curr->Next; // only move forward if no deletion
        }
    }
}

