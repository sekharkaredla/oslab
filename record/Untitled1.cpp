#include<iostream>
using namespace std;
int findMin(int x1,int x2,int **pos,int dimen,int n)
{
	int count=99999999;
	for(int i=x1;i<=x2;i++)
	{
		int temp=0;
		for(int j=0;j<n;j++)
		{
			temp+=abs(pos[dimen][j]-i);
		}
		if(temp<count)
		count=temp;
	}
	return count;
}
