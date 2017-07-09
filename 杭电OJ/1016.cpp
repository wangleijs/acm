/*Problem Description
A ring is compose of n circles as shown in diagram. Put natural number 1, 2, ..., n into each circle separately, and the sum of numbers in two adjacent circles should be a prime.

Note: the number of first circle should always be 1.


 

Input
n (0 < n < 20).
 

Output
The output format is shown as sample below. Each row represents a series of circle numbers in the ring beginning from 1 clockwisely and anticlockwisely. The order of numbers must satisfy the above requirements. Print solutions in lexicographical order.

You are to write a program that completes above process.

Print a blank line after each case.
 

Sample Input
6
8
 

Sample Output
Case 1:
1 4 3 2 5 6
1 6 5 2 3 4

Case 2:
1 2 3 8 5 6 7 4
1 2 5 8 3 4 7 6
1 4 7 6 5 8 3 2
1 6 7 4 3 8 5 2
*/
//可以用排序树进行暴力求解，这里用DFS，减少时间复杂度 
#include<stdio.h>
#include<math.h>
//int ss[21][21];快写完的时候我才发觉原来这个不需要
int visited[21];
int vex;
int pionts;
typedef struct{
	int trace[20];
	int points;
}road;
road r1;
/*void CreatGraph()
{
	int i,j;
	for(i=1;i<vex+1;i++)
		for(j=1;j<vex+1;j++)if(i==j)ss[i][j]=0;
		                 else ss[i][j]=1;
}*/
int fun(int n)//判断素数
{
	int i,flage=0;
	for(i=2;i<=(int)sqrt(1.0*n)+1;i++)if(n%i==0)flage=1;
	return !flage;
}
void DFS(int n)
{
	int i;
	visited[n]=1;
	r1.trace[r1.points]=n;
	r1.points++;
	if(r1.points==vex&&fun(n+1))
	{
		for(i=0;i<r1.points-1;i++)printf("%d ",r1.trace[i]);
		printf("%d\n",r1.trace[i]);
		return;
	}
	if(r1.points>=vex)return;
	for(i=1;i<=vex;i++)
	{
		if(n!=i&&fun(n+i)&&!visited[i])
		{
			DFS(i);
			visited[i]=0;
			r1.points--;
		}
	}
}
int main()
{
	int i,t=1;
	while(scanf("%d",&vex)!=EOF)
	{
		printf("Case %d:\n",t++);
	//	CreatGraph();
		for(i=1;i<vex+1;i++)visited[i]=0;
		r1.points=0;
		DFS(1);
		printf("\n");
	}
	return 0;
}