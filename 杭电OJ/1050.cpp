//活动安排问题 贪心算法 区间右端点非递增排列 使同一资源尽量安排多的活动
//本来以为这道题目是一个贪心算法的活动安排问题但却不然
/*#include<stdio.h>
#include<math.h>
#define inf 1000
int main()
{
	int line;
	scanf("%d",&line);
	while(line--)
	{
		int n,i,j,a,b,p,flage,t;
		int ss[200][3];
		int cor[200]={0};
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&a,&b);
			if(a>b)
			{
				t=a;
				a=b;
				b=t;
			}
			ss[i][0]=(a-1)/2;
			ss[i][1]=(b-1)/2;
			ss[i][2]=abs(ss[i][0]-ss[i][1]);
		}
		for(i=0;i<n-1;i++)
		{
			p=i;
			for(j=i+1;j<n;j++)if(ss[j][1]<ss[p][1])p=j;
			for(j=0;j<3;j++)
			{
				t=ss[i][j];
				ss[i][j]=ss[p][j];
				ss[p][j]=t;
			}
		}
		flage=1;p=0;
		while(flage)
		{
			for(i=0;i<200;i++)cor[i]=0;
			for(i=0;i<n;i++)
			{
				if(ss[i][2]==inf)continue;
				a=ss[i][0];
				b=ss[i][1];
				for(j=a;j<=b;j++)if(cor[j]==1)break;
				if(j>b)
				{
					for(j=a;j<=b;j++)cor[j]=1;
				    ss[i][2]=inf;
				}
			}
			p++;
			flage=0;
			for(i=0;i<n;i++)if(ss[i][2]!=inf)flage=1;
		}
		printf("%d\n",10*p);
	}
	return 0;
}*/
#include<stdio.h>
#include<string.h>
int main()
{
	int line,i,j,n,a,b,t,max;
	int cor[200];
	scanf("%d",&line);
	while(line--)
	{
		memset(cor,0,sizeof(cor));
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&a,&b);
			a=(a-1)/2;
			b=(b-1)/2;
			if(a>b)
			{
				t=a;
				a=b;
				b=t;
			}
			for(j=a;j<=b;j++)cor[j]++;
		}
		max=0;
		for(i=0;i<200;i++)if(cor[i]>max)max=cor[i];
		printf("%d\n",max*10);
	}
	return 0;
}
//其实每个的重复次数的最大值即为最少需要的时间，这个是正确的，是可以用数学证明的