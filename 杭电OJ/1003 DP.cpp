#include<stdio.h>
#include<stdlib.h>
int a[100005],sum[100005],ans[20][3];
int main()
{
    int ca,count=0,j;
    scanf("%d",&ca);
    for(j=0;j<ca;j++)
    {
       int n,i;
       scanf("%d",&n);
       for(i=1;i<=n;i++)
       scanf("%d",&a[i]);
       sum[1]=a[1];
       int r=1;
	   int max=a[1];//此处变量的定义若在c里面有错误在c++里就没有错误
       for(i=2;i<=n;i++)
       {
           if(sum[i-1]>0)
           {
               sum[i]=sum[i-1]+a[i];
               if(sum[i]>max)  
               {
                 max=sum[i];
                 r=i;
               }
           }
           else 
           {
             sum[i]=a[i];
               if(sum[i]>max)  
               {
                 max=sum[i];
                 r=i;
               }
           }
       }
       count++;
       for(i=r-1;i>0;i--)
       if(sum[i]<0)   break;
       ans[j][0]=max;
	   ans[j][1]=i+1;
	   ans[j][2]=r;
    }
	for(j=0;j<ca;j++)
	{ 
		printf("Case %d:\n",j+1);
       printf("%d %d %d\n",ans[j][0],ans[j][1],ans[j][2]);
       if(j!=ca-1)   printf("\n");
	}
	return 0;
}