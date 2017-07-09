#include<stdio.h>
#include<math.h>
#define pi 3.1415926
int main()
{
    int line,n,i,ans;
    double t;
    scanf("%d",&line);
    for(i=0;i<line;i++)
   {
	scanf("%d",&n);
	t=(n*log(1.0*n)-n+0.5*log(2*n*pi))/log(10.0);//斯特林公式：lnN!=NlnN-N+0.5*ln(2*N*pi)
                                                  //并且log（）在调用的时候（）参数必须是double的
                                                  //否则，杭电的编译系统不认可
	ans=(int)t+1;
	printf("%d\n",ans);
   }
   return 0;
}