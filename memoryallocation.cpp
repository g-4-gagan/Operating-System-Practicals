#include<iostream>
using namespace std;

int main()
{
	int memory,seg,np;
	cout<<"Enter the size of memory: ";
	cin>>memory;
	cout<<"Enter the number of segment: ";
	cin>>seg;
	int *ar=new int[seg];
	int *status=new int[seg];
	for(int i=0;i<seg;i++)
	{
		status[i]=0;
	}
	int temp=memory;
	cout<<"Enter the memory alloted to each segment: \n";
	for(int i=0;i<seg-1;i++)
	{
		cin>>ar[i];	
		temp=temp-ar[i];
		cout<<"Memory left: "<<temp<<endl;	
	}
	ar[seg-1]=temp;
	cout<<"Last segment has memory space of: "<<temp<<endl;
	temp=0;
	cout<<"Enter the number of processes: ";
	cin>>np;
	int* proc= new int[np];
	cout<<"Enter the memory required by each process: ";
	for(int i=0;i<np;i++)
	{
		cin>>proc[i];		
	}
	cout<<"\n\n*****************FIRST-FIT*****************\n";
	for(int i=0;i<np;i++)
	{
		for(int j=0;j<seg;j++)
		{
			if(ar[j]>=proc[i]&&status[j]==0)
			{
				cout<<"Segement "<<j+1<<" is alloted to Process: "<<i+1<<endl;
				status[j]=1;
				break;
			}
		}
	}
	for(int i=0;i<seg;i++)
	{
		status[i]=0;
	}
	cout<<"\n\n*****************BEST-FIT*****************\n";
	for(int i=0;i<np;i++)
	{
		int temp=0,alot=0,ind;
		for(int j=0;j<seg;j++)
		{
			if(ar[j]>=proc[i]&&status[j]==0)
			{
				if(alot==0)
				{
					temp=ar[j]-proc[i];
					alot=1;
					ind=j;
				}
				else
				{
					if(temp>(ar[j]-proc[i]))
					{
						temp=ar[j]-proc[i];
						ind=j;
					}					
				}
			}
		}
		if(alot!=0)
		{
			cout<<"Segement "<<ind+1<<" is alloted to Process: "<<i+1<<endl;
			status[ind]=1;
		}				
	}
	for(int i=0;i<seg;i++)
	{
		status[i]=0;
	}
	cout<<"\n\n*****************WORST-FIT*****************\n";
	for(int i=0;i<np;i++)
	{
		int temp=0,alot=0,ind;
		for(int j=0;j<seg;j++)
		{
			if(ar[j]>=proc[i]&&status[j]==0)
			{
				if(alot==0)
				{
					temp=ar[j]-proc[i];
					alot=1;
					ind=j;
				}
				else
				{
					if(temp<(ar[j]-proc[i]))
					{
						temp=ar[j]-proc[i];
						ind=j;
					}					
				}
			}
		}
		if(alot!=0)
		{
			cout<<"Segement "<<ind+1<<" is alloted to Process: "<<i+1<<endl;
			status[ind]=1;
		}				
	}
	
}
