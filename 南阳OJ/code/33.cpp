/*
�������� 
3
������� 
7 8 1
6 9 2
5 4 3
*/
/*
�뵽Ҫ����ô��仯���̣������뵽�˵ݹ���ò���������ЧӦ
���뵽Ҫģ�¹��̣������뵽��dfs��dfs��һ���ǳ��õ�ģ����̵�˼��
*/
#include<stdio.h>
#include<string.h>
int ss[100][100];
int dir[4][2]={{1,0},{0,-1},{-1,0},{0,1}};
int N,n;
void dfs(int x,int y,int d)
{
	int a=x+dir[d][0],b=y+dir[d][1];
	ss[x][y]=n++;
	if(n==N*N+1)return;
	if(a>=0&&a<N&&b>=0&&b<N&&!ss[a][b])dfs(a,b,d);
	else
	{
		d=(d+1)%4;
		a=x+dir[d][0],b=y+dir[d][1];
		dfs(a,b,d);
	}
}
int main()
{
	int i,j;
	scanf("%d",&N);
	n=1;
	memset(ss,0,sizeof(ss));
	dfs(0,N-1,0);
	for(i=0;i<N;i++)
	{
		for(j=0;j<N-1;j++)printf("%d ",ss[i][j]);
		printf("%d\n",ss[i][j]);
	}
	return 0;
}