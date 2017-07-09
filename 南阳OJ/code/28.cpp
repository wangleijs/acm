/*
样例输入 
50
样例输出 
30414093201713378043612608166064768844377641568960512000000000000
*/
#include<stdio.h>
#include<string.h>
int sa[1000000];
int main()
{
	int N,len,r,t,i,j;
	while(scanf("%d",&N)!=EOF)
	{
		memset(sa,0,sizeof(sa));
		sa[0]=1;
		len=1;
		for(i=2;i<=N;i++)//fun(i);sa=sa*i;
		{
			r=0;
			for(j=0;j<len;j++)
			{
				t=r+sa[j]*i;
				sa[j]=t%10;
				r=t/10;
			}
			while(r)
			{
				sa[j]=r%10;
				r=r/10;
				j++;
			}
			len=j;
		}
		for(i=len-1;i>=0;i--)printf("%d",sa[i]);
		printf("\n");
	}

	return 0;
}