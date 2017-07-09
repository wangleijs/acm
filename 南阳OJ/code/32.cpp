/*
样例输入 
5 3
样例输出 
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
想到了dfs把所有可能情况(路径)考虑到，输出即可，也想到了子集树，总之要递归调用
用递归的方式模拟出这个选特定子集的过程
*/
#include<stdio.h>
int ss[9]={1,2,3,4,5,6,7,8,9};
int re[9]={0};
int len;
void dfs(int n,int t)//从n之内，确定长度为len的数列的第(t+1)数，下标为t，所以只能从len-t到n之内选
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
		dfs(i-1,t+1);//以这样的递推关系，来进行递归调用
	}
}
int main()
{
	int n;
	scanf("%d %d",&n,&len);
	dfs(n,0);
	return 0;
}