#include "stdio.h" 
static int o=1;
int main()
{
    int sum,m,a,b,n,i,j,t,c,d,e,f[65];
     e=0;
    scanf("%d",&n);
    
         for(i=1;i<=n;i++)
         {   
         	sum=0; c=0; m=-1000*100000;
              scanf("%d",&a);
              for(j=1;j<=a;j++)
              {
                   scanf("%d",&b);
                   sum+=b;
                   ++c;
                   if(sum>m&&sum<1000*100000)
                   {
                        t=c;
                        m=sum;	
                   	    d=j;
                   } 
                   if(sum<0) sum=c=0;
              }	
              	f[o]=m;
              	f[++o]=d-t+1;
              	f[++o]=d;
                 ++o;
         }	 

    i=0;
    for(j=1;j<o;j+=3)
 {
		printf("Case %d:\n",j/3+1);
		printf("%d %d %d\n",f[j],f[j+1],f[j+2]);
		if((j+3)!=o)printf("\n");
 }
    	return 0;    
}
