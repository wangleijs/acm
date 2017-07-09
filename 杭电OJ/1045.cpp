/*建立可编程的数学模型   列出主要步骤，逐步求精
Sample Input
4
.X..
....
XX..
....
2
XX
.X
3
.X.
X.X
.X.
3
...
.XX
.XX
4
....
....
....
....
0
 

Sample Output
5
1
5
2
4
*/
#include<stdio.h>
#include<string.h>
int map[4][4];
int N;
void fun(int i,int j)//判断是否为交叉点
{
	int x=0,y=0;
	if(i-1>=0&&map[i-1][j]!=1000||i+1<N&&map[i+1][j]!=1000)x=1;
	if(j-1>=0&&map[i][j-1]!=1000||j+1<N&&map[i][j+1]!=1000)y=1;
	if(x*y)map[i][j]=2;
}
void fun1(int i,int j)//zei500
{
	int k;
	for(k=1;;k++)
	{
		if(i+k>=N||map[i+k][j]==1000)break;
		map[i+k][j]=500;
	}
	for(k=1;;k++)
	{
		if(i-k<0||map[i-k][j]==1000)break;
		map[i-k][j]=500;
	}
	for(k=1;;k++)
	{
		if(j+k>=N||map[i][j+k]==1000)break;
		map[i][j+k]=500;
	}
	for(k=1;;k++)
	{
		if(j-k<0||map[i][j-k]==1000)break;
		map[i][j-k]=500;
	}
}
int main()
{
	
	int i,j;
	char e;
	int count;
	while(scanf("%d",&N),N)
	{
		count=0;
		getchar();
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				e=getchar();
				if(e=='X')map[i][j]=1000;
				else if(e=='.')map[i][j]=1;
			}
			getchar();
		}
		for(i=0;i<N;i++)//判断是否为交叉点,进一步初始化map[][]
		{
			for(j=0;j<N;j++)
			{
				if(map[i][j]!=1000)
				{
					fun(i,j);
				}
			}
		}
	/*	for(i=0;i<N;i++)//printf
		{
			for(j=0;j<N;j++)
			{
				printf("%5d",map[i][j]);
			}
			printf("\n");
		}*/

		for(i=0;i<N;i++)//选1点
		{
			for(j=0;j<N;j++)
			{
				if(map[i][j]==1)
				{
					map[i][j]=500;
					fun1(i,j);
					count++;
				}
			}
		}
		for(i=0;i<N;i++)//选1点
		{
			for(j=0;j<N;j++)
			{
				if(map[i][j]==2)
				{
					map[i][j]=500;
					fun1(i,j);
					count++;
				}
			}
		}
		printf("%d\n",count);

	}

	return 0;
}