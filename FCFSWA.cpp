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
	cout<<"--------Hello world!! Welcome to FCFC scheduling with arrival--------\n";
	int n,ct=0,d;
	int *ar,*p,*a,*wt,*tt;
	cout<<"Enter the numbers of processes: ";
	cin>>n;
	ar = new int[n];
	p = new int[n];
	a = new int[n];
	wt = new int[n];
	tt = new int[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the arrival time and the burst time for P"<<i+1<<" : ";
		cin>>a[i]>>ar[i];
		p[i] = i;
	}
	cout<<"\nProcess\tarrival time\tBurst time\n";
	for(int i=0;i<n;i++)
	{
		cout<<"P"<<p[i]<<"  \t"<<a[i]<<"\t\t"<<ar[i]<<endl;
	}
	insertionSort(a,n,p,ar);
	int temp=0,sum=0;
	wt[0]=0;
	ct=a[0]+ar[0];
	for(int i=1;i<n;i++)
	{
		if(ct<a[i])
		{
			ct = a[i];
		}
//		temp=temp+ar[i-1];
        temp=ct-a[i];
		wt[i]=temp;
		sum=sum+temp;
		ct=ct+ar[i];	
	}
	int twt=sum;
	temp=0;
	sum=0;
	for(int i=0;i<n;i++)
	{
//		temp=temp+ar[i];
        temp=wt[i]+ar[i];
		tt[i]=temp;
		sum=sum+temp;	
	}	
	cout<<"\nProcess\tArrival time\tBurst time\tWaiting time\tTurnaround time\n";
	for(int i=0;i<n;i++)
	{
		cout<<"P"<<p[i]<<"  \t"<<a[i]<<"\t\t"<<ar[i]<<" \t\t"<<wt[i]<<" \t\t"<<tt[i]<<endl;
	}
	cout<<"Total waiting time for the processes is: "<<twt<<endl;
	cout<<"Average waiting time for the processes is: "<<double(twt)/n<<endl;	
	cout<<"Total turnaround time for the processes is: "<<sum<<endl;
	cout<<"Average turnaround time for the processes is: "<<double(sum)/n<<endl;
	
}
