/*
���� 
��һ¥�ݹ�m�����տ�ʼʱ���ڵ�һ������ÿ��ֻ�ܿ���һ���������Ҫ���ϵ�m�������ж����߷���

ע���涨��һ����һ����0���߷���

���� 
�����������Ȱ���һ������n(1<=n<=100)����ʾ����ʵ���ĸ�����Ȼ����n�����ݣ�ÿ�а���һ������m��
��1<=m<=40), ��ʾ¥�ݵļ����� 
��� 
����ÿ������ʵ�����������ͬ�߷��������� 
�������� 
2
2
3
������� 
1
2
*/
/*

#include<stdio.h>
#include<string.h>
using namespace std;
int ss[40];
int len,n,count;
void dfs(int i)//�����������������п�������������������ͨ���������ݷ��ֹ��ɣ�����һ��쳲����������� 
{
	if(len==n)
	{
	count++;
	return;	
	}
	if(len>n)return;
	ss[i]=1;
	len+=1;
	dfs(i+1);
	ss[i]=2;
	len=len-1+2;
	dfs(i+1);
	len-=2;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n==1)
		{
			printf("0\n");
			continue;
		}
		len=1;
		count=0;
		dfs(0);
		printf("%d\n",count);
	}
	return 0;
}*/
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int T,i;
	int ss[41]={0};
	ss[2]=1;ss[3]=2;
	for(i=4;i<41;i++)
	{
		ss[i]=ss[i-1]+ss[i-2];
	} 
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",ss[n]);
	}
	return 0;
}

