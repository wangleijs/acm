#include<stdio.h>//从广度优先遍历的角度出发解题
#include<queue>
#include<string.h>
using namespace std;
int main()
{
	int i=1;
	queue<int> Q;
	int ss[100000];
	memset(ss,0,sizeof(ss));
	Q.push(1);
	while(!Q.empty())
	{ 
		if(Q.front()+1<100000&&ss[Q.front()+1]==0)
		{
			ss[Q.front()+1]=ss[Q.front()]+1;
			Q.push(Q.front()+1);
		}
		if(Q.front()-1>0&&Q.front()-1<100000&&ss[Q.front()-1]==0)
		{
			ss[Q.front()-1]=ss[Q.front()]+1;
			Q.push(Q.front()-1);
		}
		if(Q.front()*2<100000&&ss[Q.front()*2]==0)
	    {
			ss[Q.front()*2]=ss[Q.front()]+1;
			Q.push(Q.front()*2);
		}
		Q.pop();
	}
	int line,p;
	scanf("%d",&line);
	while(line--)
	{
		scanf("%d",&p);
		printf("%d\n",ss[p]);
	}
	return 0;
}

