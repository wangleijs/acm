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
	t=(n*log(1.0*n)-n+0.5*log(2*n*pi))/log(10.0);//˹���ֹ�ʽ��lnN!=NlnN-N+0.5*ln(2*N*pi)
                                                  //����log�����ڵ��õ�ʱ�򣨣�����������double��
                                                  //���򣬺���ı���ϵͳ���Ͽ�
	ans=(int)t+1;
	printf("%d\n",ans);
   }
   return 0;
}