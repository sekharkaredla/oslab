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
        cout<<"enter arrival times : ";
        int *at=new int[n];
        for(int i=0;i<n;i++)
        cin>>at[i];
        int ct=0;
        int *wt=new int[n];
        int *tat=new int[n];
	int *cta=new int[n];
	int tq;
	cout<<"enter time quantum ";
	cin>>tq;
	int *temp=new int[n];
	for(int i=0;i<n;i++)
	temp[i]=bt[i];
	int flag=0;
	while(flag<n)
	{
		for(int i=0;i<n;i++)
		{
			if(at[i]<=ct&&bt[i]!=0)
			{
			if(bt[i]<tq)
			{
			ct+=bt[i];
			bt[i]=0;
			cta[i]=ct;
			tat[i]=cta[i]-at[i];
			wt[i]=tat[i]-temp[i];
			flag++;
			}
			else
			{
			ct+=tq;
			bt[i]-=tq;
			if(bt[i]==0)
			{
			flag++;
			cta[i]=ct;
			tat[i]=cta[i]-at[i];
			wt[i]=tat[i]-temp[i];
			}
			}
			}
		}
	}
	cout<<"\nPID\tAT\tBT\tCT\tTAT\tWT";
	for(int i=0;i<n;i++)
	{
	cout<<endl<<i<<"\t"<<at[i]<<"\t"<<temp[i]<<"\t"<<cta[i]<<"\t"<<tat[i]<<"\t"<<wt[i];
	}
	cout<<endl;
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
