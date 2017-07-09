//lnN!=NlnN-N+0.5*ln(2*N*pi)
//这个大数问题给我的感觉就是，确实够大，并且不是一般的大！  10000!=35660位  
//更改算法采用10 0000进制来计算，一个int存5为1 0000个int存5 0000位够用了
#include<stdio.h>
#include<math.h>
#include<string.h>
void fun(int *ans,int *p,int n)
{
	int i,t,r;
	for(i=0;p[i]!=-1;i++)ans[i]=p[i]*n;//char 型元素就占一个字节的单元，这里很容易容易溢出，多么不可思议的错误啊，
	                                       //我检查了一个多小时                                     
	for(i=0,r=0;p[i]!=-1;i++)
	{
		t=r+ans[i];
		ans[i]=t%10;
		r=t/10;
	}
	while(r)
	{
		ans[i]=r%10;
		r=r/10;
		i++;
	}
	ans[i]=-1;
}
int main()
{
	int i,j,n,r,p,len;
	while(scanf("%d",&n)!=EOF)
	{	
		int a[40000]={0};
		a[0]=1;len=1;
		for(i=2;i<=n;i++)
		{
			for(j=0,r=0;j<len;j++)
			{
				p=r+a[j]*i;//精妙
				a[j]=p%10;
				r=p/10;
			}
			while(r)
			{
				a[j++]=r%10;
				r=r/10;
			}
			len=j;
		}
		printf("%d",a[len-1]);
		for(i=len-2;i>=0;i--)printf("%d",a[i]);
		printf("\n");
	}
	return 0;
}