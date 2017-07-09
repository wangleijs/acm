//学习c++编程，STL queue，stack，sort函数
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1000000],b1[1000000]={0},b2[1000000]={0};//注意：一般全局的，静态的变量所允许分配的最大空间比局部的，动态的变量的要大。
int main()
{
	int m,n,i,j,p,q,max;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			b1[i]=b2[i]=0;
		}
		max=0;//对每个事例初始化max
		for(i=1;i<=m;i++)
		{
			for(j=0;j<=n;j++)
			{
				if(j==0)b2[j]=0;
				else if(i<=j)
				{
					p=max+a[j];//*max_element(b1+i-1,b1+j)+a[j];也可以不用max改为这一种算法但是会超时
					q=b2[j-1]+a[j];
					b2[j]=p>q?p:q;
					max=max>b1[j]?max:b1[j];//赋值下一个b2[j]的max
				}
				
			}			
			for(j=0;j<=n;j++)b1[j]=b2[j];
			max=b1[i];//赋值下一行的第一个(i==j时)b2[j]的max
		}
		printf("%d\n",*max_element(b2+m,b2+n+1));
	}
	return 0;
}
