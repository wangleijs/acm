//lnN!=NlnN-N+0.5*ln(2*N*pi)
//�������������ҵĸо����ǣ�ȷʵ���󣬲��Ҳ���һ��Ĵ�  10000!=35660λ  
//�����㷨����10 0000���������㣬һ��int��5Ϊ1 0000��int��5 0000λ������
#include<stdio.h>
#include<math.h>
#include<string.h>
void fun(int *ans,int *p,int n)
{
	int i,t,r;
	for(i=0;p[i]!=-1;i++)ans[i]=p[i]*n;//char ��Ԫ�ؾ�ռһ���ֽڵĵ�Ԫ����������������������ô����˼��Ĵ��󰡣�
	                                       //�Ҽ����һ����Сʱ                                     
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
				p=r+a[j]*i;//����
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