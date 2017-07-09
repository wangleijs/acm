#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct Node
{
	int x,y,z;
	friend bool operator<(Node a,Node b)//类的友元，运算符的重载，这个函数不是Node的成员函数，而是它的友元函数
	{
		return a.z>b.z;
	}
}Node; 
int main()
{
	int n,i;
	Node ss[100];
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)scanf("%d %d %d",&ss[i].x,&ss[i].y,&ss[i].z);
		sort(ss,ss+n);
		for(i=0;i<n;i++)printf("%d %d %d\n",ss[i].x,ss[i].y,ss[i].z);
		
	}
	return 0;
}
       /*   bool operator<(Node a)//类的友元，运算符的重载
	{
		return this->z>a.z;
	}
       */运算符的重载在类内也可以这样写，仔细品味