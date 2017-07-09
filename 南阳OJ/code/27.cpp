/*
描述 
南阳理工学院校园里有一些小河和一些湖泊，现在，我们把它们通一看成水池，假设有一张我们学校的某处的地图，这个地图上仅标识了此处是否是水池，现在，你的任务来了，请用计算机算出该地图中共有几个水池。

输入 
第一行输入一个整数N，表示共有N组测试数据
每一组数据都是先输入该地图的行数m(0<m<100)与列数n(0<n<100)，然后，输入接下来的m行每行输入n个数，表示此处有水还是没水（1表示此处是水池，0表示此处是地面） 
输出 
输出该地图中水池的个数。
要注意，每个水池的旁边（上下左右四个位置）如果还是水池的话的话，它们可以看做是同一个水池。

样例输入 
2
3 4
1 0 0 0 
0 0 1 1
1 1 1 0
5 5
1 1 1 1 0
0 0 1 0 1
0 0 0 0 0
1 1 1 0 0
0 0 1 1 1
样例输出 
2
3
*/
#include<stdio.h>
#include<queue>
using namespace std;
int map[100][100];
typedef struct
{
	int x,y;
}Point;
int N,M;
int movex[4]={0,1,0,-1};
int movey[4]={1,0,-1,0};
void bfs(int x,int y)
{
	int i;
	queue<Point> Q;
	Point p,e;p.x=x;p.y=y;
	map[x][y]=0;
	Q.push(p);
	while(!Q.empty())
	{
		p=Q.front();
		Q.pop();
		for(i=0;i<4;i++)
		{
			e.x=p.x+movex[i];
			e.y=p.y+movey[i];
			if(e.x>=0&&e.x<M&&e.y>=0&&e.y<N&&map[e.x][e.y]==1)
			{
				map[e.x][e.y]=0;
				Q.push(e);
			}
		}
	}
}
int main()
{
	int T,i,j,s;
	scanf("%d",&T);
	while(T--)
	{
		s=0;
		scanf("%d %d",&M,&N);
		for(i=0;i<M;i++)
			for(j=0;j<N;j++)scanf("%d",&map[i][j]);
		for(i=0;i<M;i++)
			for(j=0;j<N;j++)if(map[i][j]==1)
			{
				s++;
				bfs(i,j);
			}
		printf("%d\n",s);
	}
	return 0;
}
