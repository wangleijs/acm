/*
�������� 
5 3
������� 
543
542
541
532
531
521
432
431
421
321
*/
/*
�뵽��dfs�����п������(·��)���ǵ���������ɣ�Ҳ�뵽���Ӽ�������֮Ҫ�ݹ����
�õݹ�ķ�ʽģ������ѡ�ض��Ӽ��Ĺ���
*/
#include<stdio.h>
int ss[9]={1,2,3,4,5,6,7,8,9};
int re[9]={0};
int len;
void dfs(int n,int t)//��n֮�ڣ�ȷ������Ϊlen�����еĵ�(t+1)�����±�Ϊt������ֻ�ܴ�len-t��n֮��ѡ
{
	int i;
	if(t==len)
	{
		
		for(i=0;i<len;i++)printf("%d",re[i]);
		printf("\n");
		return ;
	}
	for(i=n;i>=len-t;i--)
	{
		re[t]=i;
		dfs(i-1,t+1);//�������ĵ��ƹ�ϵ�������еݹ����
	}
}
int main()
{
	int n;
	scanf("%d %d",&n,&len);
	dfs(n,0);
	return 0;
}