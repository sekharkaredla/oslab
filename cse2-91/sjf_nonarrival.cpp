#include<iostream>
using namespace std;
int shortest(int bt[],int done[],int n)
{
int k=0;
	for(int i=0;i<n;i++)
	{
		if(bt[k]>bt[i])
		k=i;
		else if(bt[k]==bt[i]&&i>k)
		k=i;
		
		
	}	
return k;
}
int main()
{
	int n;
	cout<<"enter no of processes :";
	cin>>n;
	int *bt=new int[n];
	cout<<"enter burst times : ";
	for(int i=0;i<n;i++)
	cin>>bt[i];
	/*cout<<"enter arrival times : ";
	int *at=new int[n];
	for(int i=0;i<n;i++)
	cin>>at[i];*/
	int ct=0;
	int *wt=new int[n];
	int *tat=new int[n];
	cout<<"PID\tCT\tWT\tTAT\n";
	int p=0;
	int *done=new int[n];
	for(int i=0;i<n;i++)
	done[i]=0;
	while(p<n)
	{
		int k=shortest(bt,done,n);
		wt[k]=ct-0;
		ct+=bt[k];
		tat[k]=ct-0;
		cout<<k<<"\t"<<ct<<"\t"<<wt[k]<<"\t"<<tat[k]<<endl;
		bt[k]=999999;
		done[k]=1;p++;
		
	}
	int awt,atat;awt=atat=0;
	for(int i=0;i<n;i++)
	{
	awt+=wt[i];
	atat+=tat[i];
	}
	awt/=n;
	atat/=n;
	cout<<"average waiting time: "<<awt<<endl;
	cout<<"average turn around time : "<<atat<<endl;
}
