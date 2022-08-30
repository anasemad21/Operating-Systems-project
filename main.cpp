#include <iostream>
using namespace std;
int part_size,process_size,choice;
class memory_allocation
{
public:
    int size_partition;
    int size_process;
    int rest_of_partition;
    memory_allocation()
    {
        size_partition=0;
        size_process=0;
        rest_of_partition=0;
    }

};
void bubble_sort(memory_allocation *array_of_partition)
{
    for(int i=0; i<part_size-1; i++)
        for(int j=i+1; j<part_size; j++)
        {
            if(array_of_partition[i].rest_of_partition>array_of_partition[j].rest_of_partition)
            {
                memory_allocation temp= array_of_partition[i];
                array_of_partition[i]=array_of_partition[j];
                array_of_partition[j]= temp;
            }
        }
}
void reverse_bubble_sort(memory_allocation *array_of_partition)
{
    for(int i=0; i<part_size-1; i++)
        for(int j=i+1; j<part_size; j++)
        {
            if(array_of_partition[i].rest_of_partition<array_of_partition[j].rest_of_partition)
            {
                memory_allocation temp= array_of_partition[i];
                array_of_partition[i]=array_of_partition[j];
                array_of_partition[j]= temp;
            }
        }
}
void insert_part(memory_allocation *array_of_partition)
{
    for(int i=0; i<part_size; i++)
    {
        cout<<"Partition"<<i+1<<" size= ";
        cin>>array_of_partition[i].size_partition;
    }
}
void insert_process(int *array_of_process)
{
    for(int i=0; i<process_size; i++)
    {
        cout<<"Process"<<i+1<<" size= ";
        cin>>array_of_process[i];
    }
}
void First_fit(memory_allocation *array_of_partition,int *array_of_process)
{
    for(int i=0; i<part_size; i++)
    {
        array_of_partition[i].rest_of_partition= array_of_partition[i].size_partition;
    }
    for(int i=0; i<process_size; i++)
    {
        for(int k=0;k<part_size;k++)
        {
            if(array_of_process[i]<=array_of_partition[k].rest_of_partition)
            {
                cout<<"partition"<<k+1<<"("<<array_of_partition[k].size_partition<<"KB)"<<"= ";
                array_of_partition[k].size_process= array_of_process[i];
                array_of_partition[k].rest_of_partition-=array_of_process[i];
                cout<<"process"<<i+1<<"("<<array_of_partition[k].size_process<<"KB), "<<"Rest of partition"<<i+1<<"= "<<array_of_partition[k].rest_of_partition<<endl;
                break;
            }
            
        }
    }
    for(int i=0; i<part_size; i++)
    {
        if(array_of_partition[i].size_process==0)
            cout<<"partition"<<i+1<<"("<<array_of_partition[i].size_partition<<"KB)"<<"= Empty.\n";
    }
}
void Worst_fit(memory_allocation *array_of_partition,int *array_of_process)
{
    for(int i=0; i<part_size; i++)
    {
        array_of_partition[i].rest_of_partition= array_of_partition[i].size_partition;
    }
    reverse_bubble_sort(array_of_partition);
    for(int i=0; i<process_size; i++)
    {
        for(int k=0; k<part_size; k++)
        {
            if(array_of_process[i]<=array_of_partition[k].rest_of_partition)
            {
                cout<<"partition"<<"("<<array_of_partition[k].size_partition<<"KB)"<<"= ";
                array_of_partition[k].size_process= array_of_process[i];
                array_of_partition[k].rest_of_partition-=array_of_process[i];
                cout<<"process"<<i+1<<"("<<array_of_partition[k].size_process<<"KB), "<<"Rest of partition"<<"= "<<array_of_partition[k].rest_of_partition<<endl;
                reverse_bubble_sort(array_of_partition);
                break;
            }

        }
    }
    for(int i=0; i<part_size; i++)
    {
        if(array_of_partition[i].size_process==0)
            cout<<"partition"<<"("<<array_of_partition[i].size_partition<<"KB)"<<"= Empty.\n";
    }
}
void Best_fit(memory_allocation *array_of_partition,int *array_of_process)
{
    for(int i=0; i<part_size; i++)
    {
        array_of_partition[i].rest_of_partition= array_of_partition[i].size_partition;
    }
    bubble_sort(array_of_partition);
    for(int i=0; i<process_size; i++)
    {
        for(int k=0; k<part_size; k++)
        {
            if(array_of_process[i]<=array_of_partition[k].rest_of_partition)
            {
                cout<<"partition"<<"("<<array_of_partition[k].size_partition<<"KB)"<<"= ";
                array_of_partition[k].size_process= array_of_process[i];
                array_of_partition[k].rest_of_partition-=array_of_process[i];
                cout<<"process"<<i+1<<"("<<array_of_partition[k].size_process<<"KB), "<<"Rest of partition"<<"= "<<array_of_partition[k].rest_of_partition<<endl;
                bubble_sort(array_of_partition);
                break;
            }
        }
    }
    for(int i=0; i<part_size; i++)
    {
        if(array_of_partition[i].size_process==0)
            cout<<"partition"<<"("<<array_of_partition[i].size_partition<<"KB)"<<"= Empty.\n";
    }
}
int main()
{
    cout<<"Enter Number of partition: ";
    cin>>part_size;
    memory_allocation *array_of_partition= new memory_allocation[part_size];
    insert_part(array_of_partition);
    cout<<endl<<"Enter Number of process: ";
    cin>>process_size;
    int* array_of_process= new int [process_size];
    insert_process(array_of_process);
    cout<<"\nSelect the policy you want to apply:\n";
    cout<<"1. First fit\n"<<"2. Worst fit\n"<<"3. Best fit\n\n";
    for(int i=0;i<3;i++)
    {
      cin>>choice;
      switch (choice)
      {
          case 1:
              First_fit(array_of_partition,array_of_process);
              break;
          case 2:
              Worst_fit(array_of_partition,array_of_process);
              break;
          case 3:
              Best_fit(array_of_partition,array_of_process);
              break;
          default:
              cout<<" Error, choice is out of range.";
              break;
      }
      cout<<"\n";
    }
    return 0;
}
