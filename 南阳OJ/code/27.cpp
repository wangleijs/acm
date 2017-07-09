/*
���� 
������ѧԺУ԰����һЩС�Ӻ�һЩ���������ڣ����ǰ�����ͨһ����ˮ�أ�������һ������ѧУ��ĳ���ĵ�ͼ�������ͼ�Ͻ���ʶ�˴˴��Ƿ���ˮ�أ����ڣ�����������ˣ����ü��������õ�ͼ�й��м���ˮ�ء�

���� 
��һ������һ������N����ʾ����N���������
ÿһ�����ݶ���������õ�ͼ������m(0<m<100)������n(0<n<100)��Ȼ�������������m��ÿ������n��������ʾ�˴���ˮ����ûˮ��1��ʾ�˴���ˮ�أ�0��ʾ�˴��ǵ��棩 
��� 
����õ�ͼ��ˮ�صĸ�����
Ҫע�⣬ÿ��ˮ�ص��Աߣ����������ĸ�λ�ã��������ˮ�صĻ��Ļ������ǿ��Կ�����ͬһ��ˮ�ء�

�������� 
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
������� 
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
