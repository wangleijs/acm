//遍历整个最小生成树即可,第一次对连通性信息采用一般的顺序查找法超时了，然后对连通性信息改用二分搜索法但还是超时没有成功 
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<set>
#include<vector>
#include<functional>
using namespace std;
typedef struct Node{
	int x, y;
	bool operator< (const Node &n2) const
	{
	    if(this->x!=n2.x)return this->x<n2.x;
    	else return this->y<n2.y;
    }
}Node;
int N;
int visited[100000],vers[100000];
multiset<Node> arcs;

void DFS(int n)
{
	
	int i;
	visited[n]=1;
	Node s;
	multiset<Node>::iterator p1=arcs.end();
	for(i=0;i<n;i++)
	{
		s.x=i;
		s.y=n;
		if(!visited[i]&&p1!=arcs.find(s))
		{vers[i]=n;
		DFS(i);}
	}
	for(i++;i<N;i++)
	{
		s.x=n;s.y=i;
		if(!visited[i]&&p1!=arcs.find(s))
		{vers[i]=n;
		DFS(i);}
	}
}
int main()
{
	int M;
	Node nt;
	scanf("%d",&M);
	while(M--)
	{
		int s,i,x,y;
		scanf("%d %d",&N,&s);
		memset(visited,0,sizeof(visited));
		for(i=0;i<N-1;i++)
		{
			scanf("%d %d",&x,&y);
			if(x>y){x=x+y;y=x-y;x=x-y;}
			nt.x=x-1;nt.y=y-1;
			arcs.insert(nt);
		}
		vers[s-1]=-2;
		DFS(s-1);
		for(i=0;i<N-1;i++)printf("%d ",vers[i]+1);
		printf("%d\n",vers[i]+1);
	}
	return 0;
}
/*
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;
int num[100001];
int word[100001];
void dfs(int n,vector<int> link[])
{
for (int i=0;i!=link[n].size();i++)
{
int k=link[n][i];
if (word[k]==0)
{
word[k]=1;
num[k]=n;
dfs(k,link);
}
}
}
int main(void)
{//freopen("love.txt","r",stdin);
int N; cin>>N;
vector<int> link[100001];
while(N--)
{
memset(word,0,sizeof(word));
int n,start;
cin>>n>>start;
for (int i=1;i<=n;i++)
{
num[i]=-1;
link[i].clear();
}
word[start]=1; num[start]=-1;
for (int i=1;i<n;i++)
{
int a,b; cin>>a>>b;
link[a].push_back(b);
link[b].push_back(a);
}
for (int i=1;i<=n;i++)
sort(link[i].begin(),link[i].end());
for (int i=0;i!=link[start].size();i++)
{
int k=link[start][i];
if (word[k]==0)
{
word[k]=1;
num[k]=start;
dfs(k,link);
}
}
for (int i=1;i<=n;i++)
{
cout<<num[i];
if (i!=n)
cout<<" ";
}
cout<<endl;
}
return 0;
}
*/
