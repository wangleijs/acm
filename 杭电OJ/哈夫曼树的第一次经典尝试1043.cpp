/*
AAAAABCD
THE_CAT_IN_THE_HAT
END
 

Sample Output
64 13 4.9
144 51 2.8
*/
#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
typedef struct{
	int num;
	int times;
}CH;
bool operator < (const CH &t1,const CH &t2)//使得队列优先输出times值小的CH节点
{
	return t1.times > t2.times;
}
int main()
{
	int database[256];
	priority_queue <CH> q;
	int tree[1000][3];
	char *ss="END";
	char sa[100000];
	int len,i,j,k,n,ans;
	float f;
	CH t,t1,t2;
	while(1)
	{
		while(!q.empty())q.pop();
		memset(database,0,sizeof(database));
	//	memset(tree)
		gets(sa);
		if(strcmp(sa,ss)==0)break;
		len=strlen(sa);
		for(i=0;i<len;i++)database[sa[i]]++;//初始化字符串基本信息
		for(i=0;i<256;i++)//建立优先队列，准备最优二叉树的生成
		{
			if(database[i])
			{
				t.num=i;
				t.times=database[i];
				q.push(t);
			}
		}
		//printf("%d %d %d\n",q.top().num,q.top().times,q.size());
		if(q.size()==1)//考虑初始队列为1个节点的情况
		{
			printf("%d %d 8.0\n",len*8,len);
			continue;
		}//到这里以上的还是对的
		n=300;k=0;
		while(q.size()!=1)//构造最优二叉树
		{
			t1=q.top();
			q.pop();
			t2=q.top();
			q.pop();
			t.num=n;
			t.times=t1.times+t2.times;
			q.push(t);
			tree[k][0]=t1.num;
			tree[k][1]=n;
			k++;
			tree[k][0]=t2.num;
			tree[k][1]=n;
			k++;n++;
		}
	//	printf("%d %d\n",k,n);
	//		for(i=0;i<k;i++)printf("%d %d\n",tree[i][0],tree[i][1]);//到这里还是对的
		for(i=k-1;i>=0;i--)//计算到达根的路径
		{
			if(i==k-1||i==k-2)tree[i][2]=1;
			for(j=k-1;j>i;j--)if(tree[j][0]==tree[i][1])
			{
				tree[i][2]=tree[j][2]+1;
			}
		}
//	for(i=0;i<k;i++)printf("%d %d %d\n",tree[i][0],tree[i][1],tree[i][2]);
		ans=0;
		for(i=0;i<k;i++)
		{
			if(tree[i][0]<300)
			{
				ans+=tree[i][2]*database[tree[i][0]];
			}
		}
		f=len*8.0/ans;
		printf("%d %d %3.1f\n",len*8,ans,f);//
	}
	return 0;
}