#include<stdio.h>
#include<math.h>
#include<string.h>
int n,m,T,dx,dy,t;
char maze[7][7];
int movex[4]={0,1,0,-1};
int movey[4]={1,0,-1,0};
bool DFS(int x,int y)
{
	if(maze[x][y]=='D')
	{
		if(t==T)return true;
		else return false;
	}
	maze[x][y]='X';
	t++;
	int tt=T-(t-1)-abs(dx-x)-abs(dy-y);
	if(tt<0||tt%2)return false;
	for(int i=0;i<4;i++)
	{
		char c=maze[x+movex[i]][y+movey[i]];//每次这里就用临时变量把需要保存的现场信息保存起来，"并列关系时"以便恢复
		int tt=t;//同上
		if(c!='X'&&x+movex[i]>=0&&x+movex[i]<n&&y+movey[i]>=0&&y+movey[i]<m)//忘了控制边界
		{
			if(DFS(x+movex[i],y+movey[i]))return true;
            maze[x+movex[i]][y+movey[i]]=c;
		    t=tt;
		}
	}
	return false;
}
int main()
{
	int sx,sy;
	while(scanf("%d %d %d",&n,&m,&T),n)
	{
		getchar();
		int i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
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
		t=0;
		if(DFS(sx,sy))printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}