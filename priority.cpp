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
	cout<<"--------Hello world!! Welcome to PRIORITY scheduling--------\n";
	int n,twt;
	int *ar,*p,*wt,*t,*pr;
	cout<<"Enter the numbers of processes: ";
	cin>>n;
	ar = new int[n];
	p = new int[n];
	pr = new int[n];
	wt = new int[n];
	t = new int[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the burst time and priority for P"<<i+1<<" : ";
		cin>>ar[i]>>pr[i];
		p[i] = i+1;
	}
	cout<<"\nProcess\tBurst time\tPriority\n";
	for(int i=0;i<n;i++)
	{
		cout<<"P"<<i+1<<"  \t"<<ar[i]<<"\t\t"<<pr[i]<<endl;
	}
	insertionSort(pr,n,p,ar);
	int temp=0,sum=0;
	wt[0]=0;
	for(int i=1;i<n;i++)
	{
		temp=temp+ar[i-1];
		wt[i]=temp;
		sum=sum+temp;	
	}
	twt = sum;
	temp=0;
	sum=0;
	for(int i=0;i<n;i++)
	{
		temp=temp+ar[i];
		t[i]=temp;
		sum=sum+temp;	
	}
	cout<<"\nProcess\tBurst time\tPriority\tWaiting time\tTurnaround time\n";
	for(int i=0;i<n;i++)
	{
		cout<<"P"<<p[i]<<"  \t"<<ar[i]<<"\t\t"<<pr[i]<<" \t\t"<<wt[i]<<" \t\t"<<t[i]<<endl;
	}
	cout<<"Total waiting time for the processes is: "<<twt<<endl;
	cout<<"Average waiting time for the processes is: "<<double(twt)/n<<endl;	
	cout<<"Total turnaround time for the processes is: "<<sum<<endl;
	cout<<"Average turnaround time for the processes is: "<<double(sum)/n<<endl;
	
}
