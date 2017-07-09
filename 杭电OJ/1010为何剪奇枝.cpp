/*Sample Input (1 < N, M < 7; 0 < T < 50), 
4 4 5
S.X.
..X.
..XD
....
3 4 5
S.X.
..X.
...D
0 0 0
 

Sample Output
NO
YES
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
char maze[7][7];
int N,M,T;
int sx,sy,dx,dy;
int flage,points;
int movex[4]={0,1,0,-1};
int movey[4]={1,0,-1,0};
void CreatGraph()
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			scanf("%c",&maze[i][j]);
			if(maze[i][j]=='S')
			{
				sx=i;
				sy=j;
			}
			else if(maze[i][j]=='D')
			{
				dx=i;
				dy=j;
			}
		}
		getchar();
	}
}
void DFS(int x,int y)
{
	int i,t;
	char e;
	points++;
	maze[x][y]='X';
	if(points==T+1&&x==dx&&y==dy)
	{
		flage=1;
		return;
	}
	t=T+1-points-abs(dx-x)-abs(dy-y);
	if(t<0||t%2)return;//这个剪枝比较特殊，但是在应用到maze问题时，这种剪枝一定要会应用不能是(t<=0||t%2)
	for(i=0;i<4;i++)
	{
		if(x+movex[i]>=0&&x+movex[i]<=N-1&&y+movey[i]>=0&&y+movey[i]<=M-1&&maze[x+movex[i]][y+movey[i]]!='X')
		{
			e=maze[x+movex[i]][y+movey[i]];
			DFS(x+movex[i],y+movey[i]);
			points--;
			maze[x+movex[i]][y+movey[i]]=e;
			if(flage)return;//剪枝关键
		}
	}

}
int main()
{
	while(1)
	{
		scanf("%d %d %d",&N,&M,&T);
		getchar();
		if(N==0&&M==0&&T==0)break;
		CreatGraph();
		flage=points=0;
		DFS(sx,sy);
		flage?printf("YES\n"):printf("NO\n");
	}
	return 0;
}
//这个题目剪枝很重要如果不进行必要的剪枝一定会Time Limit Exceeded
//还有一个困惑是为何要减奇数枝