/*
描述 
zyc从小就比较喜欢玩一些小游戏，其中就包括画一笔画，他想请你帮他写一个程序，判断一个图是否能够用一笔画下来。

规定，所有的边都只能画一次，不能重复画。

 

输入 
第一行只有一个正整数N(N<=10)表示测试数据的组数。
每组测试数据的第一行有两个正整数P,Q(P<=1000,Q<=2000)，分别表示这个画中有多少个顶点和多少条连线。（点的编号从1到P）
随后的Q行，每行有两个正整数A,B(0<A,B<P)，表示编号为A和B的两点之间有连线。 
输出 
如果存在符合条件的连线，则输出"Yes",
如果不存在符合条件的连线，输出"No"。 

样例输入 
2
4 3
1 2
1 3
1 4
4 5
1 2
2 3
1 3
1 4
3 4
样例输出 
No
Yes
*/
/*
一笔画定理
1736年，欧拉证实：七桥问题的走法根本不存在。同时，他发表了“一笔画定理”：
一个图形要能一笔画完成必须符合两个条件，即图形是封闭联通的和图形中的奇点（与奇数条边相连的点）个数为0或2。
欧拉的研究开创了数学上的新分支――拓扑学的先声。
*/
#include<stdio.h>
#include<string.h>
char map[1000][1000];
int T,n,m,i,j,a,b,flage;
void fun()//经过优化了
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<i;j++)if(map[i][j])return;
	flage=1;
}
void dfs(int a)
{
	int i,is=1;
	for(i=0;i<n;i++)
	{
		if(flage)return;
		if(map[a][i]&&i!=a)
		{
			map[a][i]=map[i][a]=0;
			dfs(i);
			map[a][i]=map[i][a]=1;
			is=0;
		}
	}
	if(is)fun();
}
int main()
{
	int t,s;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		memset(map,0,sizeof(map));
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&a,&b);
			map[a-1][b-1]=1;
			map[b-1][a-1]=1;
		}
		s=0;
		for(i=0;i<n;i++)
		{
			t=0;
			for(j=0;j<n;j++)if(map[i][j])t++;
			if(t%2)s++;
		}
		if(!(s==0||s==2))
		{
			printf("No\n");
			continue;
		}
		flage=0;
		for(i=0;i<n;i++)
		{
			if(flage)break;
			dfs(i);
		}
		if(flage)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
