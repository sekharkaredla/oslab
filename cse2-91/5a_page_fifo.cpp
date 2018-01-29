#include<iostream>
#include<stdbool.h>
using namespace std;
void display(int *s,int n,bool flag)
{
	for(int i=0;i<n;i++)
	{
	cout<<'\t'<<s[i];
	}
	if(flag)
	cout<<"\tHIT"<<endl;
	else
	cout<<endl;
}
int main()
{
	cout<<"\nenter no of sequences : ";
	int n;
	cin>>n;
	int *s=new int[n];
	cout<<"\nenter the sequences:";
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	int f;
	cout<<"\nenter the frame size : ";
	cin>>f;
	int *fr=new int[f];
	for(int i=0;i<f;i++)
	fr[i]=-1;
	int size=0;int hit=0;int insert=0;int flag;
	for(int i=0;i<n;i++)
	{
		insert=0;flag=0;
		for(int j=0;j<f;j++)
		{
		if(fr[j]==s[i])
		{j=f;hit++;flag=1;display(fr,f,true);}
		if(fr[j]==-1)
		{fr[j]=s[i];insert=1;size++;j=f;display(fr,f,false);}
		}
		if(insert==1)
		continue;
		else if(flag==0)
		{
		fr[f-size]=s[i];
		size--;
		if(size==0)
		size=f;
		}
	}
	for(int i=0;i<f;i++)
	cout<<'\t'<<s[i];
	cout<<endl;
	cout<<"\nnumber of faults:"<<(n-hit);
	float temp=float(hit)/float(n);
	cout<<"\nhit ratio:"<<temp;
	cout<<"\nmiss ratio:"<<(1.0-temp)<<endl;


}
