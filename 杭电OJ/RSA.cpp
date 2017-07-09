/*
Sample Input
1 
2 
26 
125 
3125 
9999
 

Sample Output
1
2
4
8
2
8
*/
/*
*/
#include<stdio.h>
#include<math.h>
int n=18923;
int fun(int a,int j)
{
	int i,t=a;
	for(i=2;i<=j;i++)
	{
		t=(t*a)%n;
	}
	return t;
}
int main()
{
	int p=149,q=127,a=2,j;
/*	for(j=2;;j++)
	{
		a=fun(a,j);
		if((a-1)%p==0||(a-1)%q==0)break;
	}*/
printf("%d",fun(11431,8));
//	printf("%d %d",j,a);
	
       return 0;
}
