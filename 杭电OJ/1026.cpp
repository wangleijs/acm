//学习c++编程，queue，stack，sort函数
#include<stdio.h>
#include<queue>
#include<stack>
#include<string.h>
#define inf 1000000
using namespace std;
typedef struct{
	int i,j;
}Point;
typedef struct{
	int cost;
	int time;
	Point prep;
}Node;
int N,M;
int movex[4]={0,1,0,-1};
int movey[4]={1,0,-1,0};
Node maze[100][100];
void BFS()
{
	queue<Point> q;
	Point p;
	p.i=p.j=0;
	maze[p.i][p.j].time=0;
	maze[p.i][p.j].prep.i=maze[p.i][p.j].prep.j=-1;
	q.push(p);
	while(!q.empty())
	{
		Point p=q.front();
		q.pop();
		if(p.i==N-1&&p.j==M-1)continue;
		for(int i=0;i<4;i++)
		{
			Point p1;
			p1.i=p.i+movex[i];
			p1.j=p.j+movey[i];
			if(p1.i>=0&&p1.i<N&&p1.j>=0&&p1.j<M)
			{
				if(maze[p.i][p.j].time+maze[p1.i][p1.j].cost<maze[p1.i][p1.j].time)
				{
					maze[p1.i][p1.j].time=maze[p.i][p.j].time+maze[p1.i][p1.j].cost;
					maze[p1.i][p1.j].prep=p;
					q.push(p1);
				}
			}
		}
	}
}
int main()
{
	int i,j;
	while(scanf("%d %d",&N,&M)!=EOF)
	{
	getchar();//忘了写，检查了一个小时，快要疯了，这样的错误接二连三的经常犯，以后一定要注意
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			char c;
			scanf("%c",&c);
			if(c=='X')maze[i][j].cost=inf;
			else if(c=='.')maze[i][j].cost=1;
			else maze[i][j].cost=c-'0'+1;
			maze[i][j].time=inf;
		}
		getchar();
	}
	BFS();
	if(maze[N-1][M-1].time==inf)
	{
		printf("God please help our poor hero.\nFINISH\n");
		continue;
	}
	Point p;
	p.i=N-1;
	p.j=M-1;
	stack<Point> s;
	s.push(p);
	while(1)
	{
		p=maze[s.top().i][s.top().j].prep;
		if(p.i==0&&p.j==0)break;
		s.push(p);
	}
	printf("It takes %d seconds to reach the target position, let me show you the way.\n",maze[N-1][M-1].time);
	Point p1,p2;
	p1.i=p1.j=0;
	int t=1;
	while(!s.empty())
	{
		p2=s.top();
	    s.pop();
		printf("%ds:(%d,%d)->(%d,%d)\n",t++,p1.i,p1.j,p2.i,p2.j);
		for(i=1;i<maze[p2.i][p2.j].cost;i++)printf("%ds:FIGHT AT (%d,%d)\n",t++,p2.i,p2.j);
		p1=p2;
	}
	printf("FINISH\n");

	}
	return 0;
}
