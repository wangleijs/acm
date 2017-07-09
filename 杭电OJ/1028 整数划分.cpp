#include<stdio.h>
int main()
{
    int ans[121][121];
    int i,j,n;
    for(i=1;i<121;i++)
    {
        for(j=1;j<121;j++)
        {
            if(j==1)ans[i][j]=1;
            else
            {
                if(j>i)ans[i][j]=ans[i][i];
                if(j==i)ans[i][j]=ans[i][j-1]+1;
                if(j<i)ans[i][j]=ans[i][j-1]+ans[i-j][j];
            }
        }
    }
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",ans[n][n]);
    }
    return 0;
}
