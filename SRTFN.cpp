#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
  int n; //number of processes
  int *process,*burst_time,*waiting_time,*completion_time,*turn_around_time,*arrival_time,t_wt=0,t_tat=0;
  process=new int[n];
  burst_time=new int[n];
  waiting_time=new int[n];
  completion_time=new int[n];
  turn_around_time=new int[n];
  arrival_time=new int[n];
  float avg_wt=0.0,avg_tat=0.0;
  int temp;
  int value;

  cout<<"\n Enter the number of processes : ";
  cin>>n;
  cout<<"\nEnter burst time : "<<endl;
  for(int i=0;i<n;i++)
  {
    process[i]=i+1;
    cout<<"P["<<i+1<<"]:";
    cin>>burst_time[i];
  }
  cout<<"\nEnter arrival time  : "<<endl;
  for(int i=0;i<n;i++)
  {
    cout<<"P["<<i+1<<"]:";
    cin>>arrival_time[i];
  }
  cout<<"\n INPUT DATA ";
  cout<<"\nProcess"<<" \t"<<"Arrival Time"<<" \t"<<"Burst Time"<<endl;
  for(int i=0;i<n;i++)
  {
    cout<<"\nP["<<process[i]<<"]"<<"\t\t"<<arrival_time[i]<<"\t\t"<<burst_time[i]<<endl;
  }
//sort_arrival_time
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(arrival_time[i]>arrival_time[j])
      {
        swap(process[i],process[j]);
        swap(arrival_time[i],arrival_time[j]);
        swap(burst_time[i],burst_time[j]);
      }

      if(arrival_time[i]==arrival_time[j])
      // Condition is checked if two processes have same arrival time.
      {
        if(burst_time[i]>burst_time[j])
        // In case the arrival time is same, the processes are compared according to their burst time and further sorted.
        {
          swap(process[i],process[j]);
          swap(arrival_time[i],arrival_time[j]);
          swap(burst_time[i],burst_time[j]);
    }
  }
}
}
  completion_time[0] = arrival_time[0] + burst_time[0];
  turn_around_time[0] = completion_time[0] - arrival_time[0];
  waiting_time[0] = turn_around_time[0] - burst_time[0];
// sort_burst_time
  for(int i=1;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
        if(burst_time[i]>burst_time[j])
        {
          swap(process[i],process[j]);
          swap(arrival_time[i],arrival_time[j]);
          swap(burst_time[i],burst_time[j]);
        }

        if(burst_time[i]==burst_time[j])
        {
        	if(arrival_time[i]>arrival_time[j])
        	{
        	
          swap(process[i],process[j]);
          swap(arrival_time[i],arrival_time[j]);
          swap(burst_time[i],burst_time[j]);
        }
        }
	if(arrival_time[i]>completion_time[i-1])
	{
          swap(process[i],process[j]);
          swap(arrival_time[i],arrival_time[j]);
          swap(burst_time[i],burst_time[j]);
    }
      }
    completion_time[i] = completion_time[i-1]+ burst_time[i];
    turn_around_time[i] = completion_time[i] - arrival_time[i];
    waiting_time[i] = turn_around_time[i] - burst_time[i];
}
  cout<<"\n OUTPUT DATA";
  cout<<"\nProcess"<<" \t"<<"Arrival Time"<<" \t"<<"Burst Time"<<" \t"<<"Waiting Time"<<" \t"<<"Turn Around Time"<<endl;
  for(int i=0;i<n;i++)
  {
    cout<<"\nP["<<process[i]<<"]"<<"\t\t"<<arrival_time[i]<<"\t\t"<<burst_time[i]<<"\t\t"<<waiting_time[i]<<"\t\t"<<turn_around_time[i]<<endl;
  }
  cout<<endl<<endl;
    //calculating total waiting and turnaround time
    for(int i=0;i<n;i++)
    {
        t_wt+=waiting_time[i];
        t_tat+=turn_around_time[i];
    }
 
    avg_wt=(float) t_wt/n;
    avg_tat=(float) t_tat/n;
    cout<<"\n\nAverage Waiting Time:"<<avg_wt;
    cout<<"\n\nAverage Turnaround Time:"<<avg_tat;
  return 0;
}

