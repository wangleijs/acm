//ѧϰc++��̣�STL queue��stack��sort����
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1000000],b1[1000000]={0},b2[1000000]={0};//ע�⣺һ��ȫ�ֵģ���̬�ı����������������ռ�Ⱦֲ��ģ���̬�ı�����Ҫ��
int main()
{
	int m,n,i,j,p,q,max;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			b1[i]=b2[i]=0;
		}
		max=0;//��ÿ��������ʼ��max
		for(i=1;i<=m;i++)
		{
			for(j=0;j<=n;j++)
			{
				if(j==0)b2[j]=0;
				else if(i<=j)
				{
					p=max+a[j];//*max_element(b1+i-1,b1+j)+a[j];Ҳ���Բ���max��Ϊ��һ���㷨���ǻᳬʱ
					q=b2[j-1]+a[j];
					b2[j]=p>q?p:q;
					max=max>b1[j]?max:b1[j];//��ֵ��һ��b2[j]��max
				}
				
			}			
			for(j=0;j<=n;j++)b1[j]=b2[j];
			max=b1[i];//��ֵ��һ�еĵ�һ��(i==jʱ)b2[j]��max
		}
		printf("%d\n",*max_element(b2+m,b2+n+1));
	}
	return 0;
}
