/*
Sample Input
5 6
.XX.1.
..X.2.
2...X.
...XX.
XXXXX.
5 6
.XX.1.
..X.2.
2...X.
...XX.
XXXXX1
5 6
.XX...
..XX1.
2...X.
...XX.
XXXXX.
 

Sample Output
It takes 13 seconds to reach the target position, let me show you the way.
1s:(0,0)->(1,0)
2s:(1,0)->(1,1)
3s:(1,1)->(2,1)
4s:(2,1)->(2,2)
5s:(2,2)->(2,3)
6s:(2,3)->(1,3)
7s:(1,3)->(1,4)
8s:FIGHT AT (1,4)
9s:FIGHT AT (1,4)
10s:(1,4)->(1,5)
11s:(1,5)->(2,5)
12s:(2,5)->(3,5)
13s:(3,5)->(4,5)
FINISH
It takes 14 seconds to reach the target position, let me show you the way.
1s:(0,0)->(1,0)
2s:(1,0)->(1,1)
3s:(1,1)->(2,1)
4s:(2,1)->(2,2)
5s:(2,2)->(2,3)
6s:(2,3)->(1,3)
7s:(1,3)->(1,4)
8s:FIGHT AT (1,4)
9s:FIGHT AT (1,4)
10s:(1,4)->(1,5)
11s:(1,5)->(2,5)
12s:(2,5)->(3,5)
13s:(3,5)->(4,5)
14s:FIGHT AT (4,5)
FINISH
God please help our poor hero.
FINISH
*/
#include<stdio.h>
#include<string.h>
typedef struct {
	int x,y,n;
}Point;
Point path[10000];
Point patht[10000];
int N,M,len,lent,cost,costt,is;
char map[100][100];
int movx[4]={0,1,0,-1};
int movy[4]={1,0,-1,0};
void DFS(int i,int j)
{
	int k;
	patht[lent].x=i;
	patht[lent].y=j;
	if(map[i][j]>'0'&&map[i][j]<='9')patht[lent].n=map[i][j]-'0';
	else patht[lent].n=0;
	costt+=(1+patht[lent].n);
	lent++;
	map[i][j]='X';
//	printf("%d %d\n",i,j);
	if(i==N-1&&j==M-1&&costt<cost)//ÎóÐ´³ÉN M£¬°¥ 
	{
//		printf("hah");
		is=1;
		for(k=0;k<lent;k++)
		{
			path[k].n=patht[k].n;
			path[k].x=patht[k].x;
			path[k].y=patht[k].y;
		}
		len=lent;
		cost=costt;
	}
	
    if(i==N-1&&j==M-1)
	{
	    return;
	}
	for(k=0;k<4;k++)
	{
	//	printf("hah \n");
		if(map[i+movx[k]][j+movy[k]]!='X'&&i+movx[k]>=0&&i+movx[k]<N&&j+movy[k]>=0&&j+movy[k]<M)
		{
			int a=lent;
			int b=costt;
			char c=map[i+movx[k]][j+movy[k]];
			DFS(i+movx[k],j+movy[k]);
			lent=a;
			costt=b;
			map[i+movx[k]][j+movy[k]]=c;
		}
	}

}
int main()
{
	int i,j;
	while(scanf("%d %d",&N,&M)!=EOF)
	{
		getchar();
		for(i=0;i<N;i++)
		{
			for(j=0;j<M;j++)
			{
				scanf("%c",&map[i][j]);
			}
			getchar();
		}
		is=lent=costt=0;
		cost=1000000;
		DFS(0,0);
		if(is==0)
		{
			printf("God please help our poor hero.\nFINISH\n");
			continue;
		}
		int t=1;
		printf("It takes %d seconds to reach the target position, let me show you the way.\n",cost-1);
		for(i=1;i<len;i++)
		{
			printf("%ds:(%d,%d)->(%d,%d)\n",t++,path[i-1].x,path[i-1].y,path[i].x,path[i].y);
			for(j=0;j<path[i].n;j++)
			{
				printf("%ds:FIGHT AT (%d,%d)\n",t++,path[i].x,path[i].y);
			}
		}
		printf("FINISH\n");
	}
	return 0;
}