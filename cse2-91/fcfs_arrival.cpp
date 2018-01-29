#include<iostream>
using namespace std;
int shortest(int at[],int done[],int n)
{
int k=0;
	for(int i=0;i<n;i++)
	{
		if(at[k]>at[i]&&done[i]!=1)
		k=i;
		else if(at[k]==at[i]&&done[i]!=1)
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
        cout<<"enter arrival times : ";
        int *at=new int[n];
        for(int i=0;i<n;i++)
        cin>>at[i];
        int ct=0;
        int *wt=new int[n];
        int *tat=new int[n];
        cout<<"PID\tAT\tBT\tCT\tWT\tTAT\n";
	int p=0;
	int *done=new int[n];
	for(int i=0;i<n;i++)
	done[i]=0;
        while(p<n)
        {
             	/*for(int i=0;i<n;i++)
		{
		if(at[i]<=ct)
		{
                wt[i]=ct;
                ct+=bt[i];
                tat[i]=ct-;
                cout<<i<<"\t"<<ct<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl;p++;
		}
		}*/
	//	for(int i=0;i<n;i++)
	//	{
	//	if(at[i]<=ct&&done[i]!=1)
	//	{
			int i=shortest(at,done,n);
			wt[i]=ct-at[i];
			ct+=bt[i];
			tat[i]=ct-at[i];
			cout<<i<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl;p++;
			at[i]=99999;
			done[i]=1;
		//}
	}
        float awt,atat;awt=atat=0.0;
        for(int i=0;i<n;i++)
        {
        awt+=wt[i];
        atat+=tat[i];
        }
        awt=float(awt/n);
        atat=float(atat/n);
        cout<<"average waiting time: "<<awt<<endl;
        cout<<"average turn around time : "<<atat<<endl;
}

