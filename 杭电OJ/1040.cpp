#include<stdio.h>
int ss[1000];
void sort(int n)
{
    int i,j,p,t;
    for(i=0;i<n-1;i++)
    {
        p=i;
        for(j=i;j<n;j++)if(ss[j]<ss[p])p=j;
        t=ss[i];
        ss[i]=ss[p];
        ss[p]=t;
    }
}
int main()
{
   int line,n,i,j;

   scanf("%d",&line);
   for(i=0;i<line;i++)
   {
       scanf("%d",&n);
       for(j=0;j<n;j++)scanf("%d",ss+j);
       sort(n);
       for(j=0;j<n-1;j++)printf("%d ",ss[j]);
       printf("%d\n",ss[n-1]);
   }
   return 0;
}
