#include<iostream>
using namespace std;

void insertionSort(int arr[], int n,int p[],int t[])  
{  
    int i, key, j,pos,time;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i]; 
		pos = p[i];
		time = t[i] ;
        j = i - 1;  
  
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];
			p[j+1] = p[j];
			t[j+1] = t[j];    
            j = j - 1;  
        }  
        arr[j + 1] = key;
		p[j+1] = pos;
		t[j+1] = time;   
    }  
}  

int main()
{
	cout<<"--------Hello world!! Welcome to SRTF scheduling--------\n";
	int n,twt;
	int *p,*ar,*rt,*at,*wt,*t;
	cout<<"Enter the numbers of processes: ";
	cin>>n;
	ar = new int[n];
	p = new int[n];
	rt = new int[n];
	at= new int[n];
	wt = new int[n];
	t = new int[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the arrival time and the burst time for P"<<i+1<<" : ";
		cin>>at[i]>>ar[i];
		p[i] = i+1;
	}
	cout<<"\nProcess\tArrival time\tBurst time\n";
	for(int i=0;i<n;i++)
	{
		cout<<"P"<<i+1<<"  \t"<<at[i]<<"\t\t"<<ar[i]<<endl;
	}
	insertionSort(at,n,p,rt);
	cout<<"\nProcess\tArrival time\tBurst time\n";
	for(int i=0;i<n;i++)
	{
		cout<<"P"<<i+1<<"  \t"<<at[i]<<"\t\t"<<ar[i]<<endl;
	}
	
}
