#include<stdio.h>
int main()
{
    int n,m,k,i,j,p;
    float nm[1000];
	float t;
    int ans[1000];
    while(scanf("%d %d %d",&n,&m,&k)!=EOF)
    {
        for(j=0;j<1000;j++)nm[j]=0.0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%f",&t);
                nm[j]+=t;
            }
        }
        for(i=0;i<k;i++)
        {
            p=0;
            for(j=1;j<m;j++)
            {
                if(nm[j]>nm[p])p=j;
            }
            ans[i]=p;
            nm[p]=0;
        }
        for(i=0;i<k;i++)
        {
            p=0;
            for(j=1;j<k;j++)if(ans[j]>ans[p])p=j;
            if(i!=(k-1))printf("%d ",ans[p]+1);
            else printf("%d",ans[p]+1);
            ans[p]=-1;
        }
        printf("\n");
    }
    return 0;
}
