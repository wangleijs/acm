#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct Node
{
	int x,y,z;
	friend bool operator<(Node a,Node b)//�����Ԫ������������أ������������Node�ĳ�Ա����������������Ԫ����
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
       /*   bool operator<(Node a)//�����Ԫ�������������
	{
		return this->z>a.z;
	}
       */�����������������Ҳ��������д����ϸƷζ