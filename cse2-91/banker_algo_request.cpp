#include<iostream>
#include<stdlib.h>
#include<stdbool.h>
using namespace std;
void display(int **a,int n,int m)
{
	for(int i=0;i<n;i++)
	{
	cout<<endl;
	for(int j=0;j<m;j++)
	cout<<a[i][j]<<"  ";
	}
}
bool isSmall(int *a,int *b,int n)
{
        int flag=0;
        for(int i=0;i<n;i++)
        {
        if(a[i]>b[i])
        {
        flag=1;
        break;
        }
        }
        if(flag==0)
        return true;
        else
        return false;
}

int main()
{
	cout<<"\nenter no of variety of resources : ";
	int nr;
	cin>>nr;
	cout<<"enter the instances of resources : ";
	int *r=new int[nr];
	for(int i=0;i<nr;i++)
	cin>>r[i];
	cout<<"enter the no of processes : ";
	int p;
	cin>>p;
	cout<<"enter the allocation matrix : ";
	int **am=new int*[p];
	for(int i=0;i<p;i++)
	am[i]=new int[nr]; 
	for(int i=0;i<p;i++)
	for(int j=0;j<nr;j++)
	cin>>am[i][j];
	cout<<"enter the max matrix : ";
        int **mm=new int*[p]; 
        for(int i=0;i<p;i++) 
        mm[i]=new int[nr]; 
        for(int i=0;i<p;i++)
        for(int j=0;j<nr;j++)
        cin>>mm[i][j];	
        int **nm=new int*[p]; 
        for(int i=0;i<p;i++) 
        nm[i]=new int[nr]; 
        for(int i=0;i<p;i++)
        for(int j=0;j<nr;j++)
        nm[i][j]=mm[i][j]-am[i][j];
	display(nm,p,nr);
	int *avai=new int[nr];
	int *temp=new int[nr];
	cout<<"\nenter the process that is requesting :";
	int rp;
	cin>>rp;
	cout<<"\nenter the request : ";
	int *request=new int[nr];
	for(int i=0;i<nr;i++)
	cin>>request[i];
	if(isSmall(request,nm[rp],nr)&&isSmall(request,avai,nr))
	{
		for(int i=0;i<nr;i++)
		{
		avai[i]-=request[i];
		nm[rp][i]-=request[i];
		am[rp][i]+=request[i];
		}
			
	} 
	for(int i=0;i<nr;i++)
	{
	int sum=0;
	for(int j=0;j<p;j++)
	{
	sum+=am[j][i];
	}
	temp[i]=sum;
	}
	int *work=new int[nr];
	for(int i=0;i<nr;i++)
	{
	avai[i]=r[i]-temp[i];
	work[i]=avai[i];
	}
	bool *finish=new bool[p];
	for(int i=0;i<p;i++)
	finish[i]=false;
	int trap=0;
	int count=0;
	int disp=1;
	//cout<<"\nsafe sequence :";
	while(trap<p)
	{
		if(count>p*p)
		{cout<<"unsafe";
			break;
		}
		
		for(int i=0;i<p;i++)
		{count++;
			if(finish[i]==false&&isSmall(nm[i],work,nr))
			{
				if(disp==1)
				cout<<"\nsafe sequence :";
				disp++;
				for(int j=0;j<nr;j++)
				work[j]=work[j]+am[i][j];
				trap++;
				finish[i]=true;	
				cout<<i<<"  ";
			}
			
		}
	}
	

}
