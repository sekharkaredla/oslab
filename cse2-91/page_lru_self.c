#include<stdio.h>
#include<stdbool.h>
int getI(int *s,int i,int p,int *fr,int f)
{
	int j,k;int temp=0;int index;
	for(j=0;j<f;j++)
	{
		for(k=i;k>=0;k--)
		{
		if(s[k]==fr[j])
		{
//			printf("%d hi",temp);
			if(temp<=i-k)
			{
			temp=i-k;
			index=j;
			k=-1;
			}
		
		}
		}
	}
return index;
}
void display(int *fr,int f,bool flag)
{
	int i;
	for(i=0;i<f;i++)
	{
	printf("\t%d",fr[i]);
	}
	if(flag)
	printf("\tHIT\n");
	else
	printf("\n");
}
void main()
{
	int p;
	printf("enter the number of pages:");
	scanf("%d",&p);
	int s[p];
	int i,j;
	printf("enter the sequences:");
	for(i=0;i<p;i++)
	scanf("%d",&s[i]);
	int f;
	printf("enter the frame size:");
	scanf("%d",&f);
	int fr[f];
	for(i=0;i<f;i++)
	fr[i]=-1;
	int insert=0;int hit=0;
	for(i=0;i<p;i++)
	{insert=0;
		for(j=0;j<f;j++)
		{
		if(fr[j]==-1)
		{
		fr[j]=s[i];
		j=f;
		display(fr,f,false);insert=1;
		}
		}
		if(insert==1)
		continue;
		for(j=0;j<f;j++)
		{
		if(fr[j]==s[i])
		{
		hit++;
		insert=1;
		display(fr,f,true);
		}
		}
		if(insert==1)
		continue;
		int tempi=getI(s,i-1,p,fr,f);
		fr[tempi]=s[i];
		display(fr,f,false);
	}
	
}
