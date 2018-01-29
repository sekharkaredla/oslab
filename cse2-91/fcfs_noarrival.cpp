#include<iostream>
using namespace std;
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
	for(int i=0;i<n;i++)
	{
		//ct+=bt[i];
		wt[i]=ct;
		ct+=bt[i];
		tat[i]=ct-0;
		//cout<<"PID : "<<i<<" completion time:"<<ct<<endl;
		cout<<i<<"\t"<<ct<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl;
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
