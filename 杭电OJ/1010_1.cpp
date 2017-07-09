#include<stdio.h>
#include<math.h> 
#include<string.h>
int t,T,N,M,sx,sy,dx,dy,is;
int map[7][7];
int movex[4]={0,1,0,-1};
int movey[4]={1,0,-1,0};
void DFS(int x,int y)
{
	if(is==1)return;
	if(x==dx&&y==dy)
	{
		if(t==T)is=1;
		return;
	}
	int i,a,b,tt;
	char c;
	for(i=0;i<4;i++)//在走到（a，b）之前先判断能不能走到（a，b），以及提起设置走到（a，b）后的参数变化 
	{
		a=x+movex[i];
		b=y+movey[i];
		if(a>=0&&a<N&&b>=0&&b<M)
		if(map[a][b]!='X')
		if((T-t-1)>=(abs(dx-a)+abs(dy-b))) 
		if(((T-t-1)-abs(dx-a)-abs(dy-b))%2==0)
		{
			c=map[a][b];
			t++;
			map[a][b]='X';
			DFS(a,b);
			map[a][b]=c;
			t--; 
		}
	}
}
int main()
{
	while(scanf("%d %d %d",&N,&M,&T),N)
	{
		getchar();
		int i,j;
		for(i=0;i<N;i++)
		{
			for(j=0;j<M;j++)
			{
				scanf("%c",&map[i][j]);
				if(map[i][j]=='S')
				{
					sx=i;sy=j;
				}
				else if(map[i][j]=='D')
				{
					dx=i;dy=j;
				}
			}
			getchar();
		}
		
		t=0;is=0;
		map[sx][sy]='X';//这一步万万不能忘 
		DFS(sx,sy);
		is?printf("YES\n"):printf("NO\n");
		
	}
	return 0;
}
