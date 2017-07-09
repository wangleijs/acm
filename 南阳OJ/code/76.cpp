/*
描述 
有一楼梯共m级，刚开始时你在第一级，若每次只能跨上一级或二级，要走上第m级，共有多少走法？

注：规定从一级到一级有0种走法。

输入 
输入数据首先包含一个整数n(1<=n<=100)，表示测试实例的个数，然后是n行数据，每行包含一个整数m，
（1<=m<=40), 表示楼梯的级数。 
输出 
对于每个测试实例，请输出不同走法的数量。 
样例输入 
2
2
3
样例输出 
1
2
*/
/*

#include<stdio.h>
#include<string.h>
using namespace std;
int ss[40];
int len,n,count;
void dfs(int i)//暴力收索，考虑所有可能情况，。。。。最后通过测试数据发现规律，这是一组斐波那契额数列 
{
	if(len==n)
	{
	count++;
	return;	
	}
	if(len>n)return;
	ss[i]=1;
	len+=1;
	dfs(i+1);
	ss[i]=2;
	len=len-1+2;
	dfs(i+1);
	len-=2;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n==1)
		{
			printf("0\n");
			continue;
		}
		len=1;
		count=0;
		dfs(0);
		printf("%d\n",count);
	}
	return 0;
}*/
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int T,i;
	int ss[41]={0};
	ss[2]=1;ss[3]=2;
	for(i=4;i<41;i++)
	{
		ss[i]=ss[i-1]+ss[i-2];
	} 
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",ss[n]);
	}
	return 0;
}

