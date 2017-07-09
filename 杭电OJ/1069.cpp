/*
Sample Input
1
10 20 30
2
6 8 10
5 5 5
7
1 1 1
2 2 2
3 3 3
4 4 4
5 5 5
6 6 6
7 7 7
5
31 41 59
26 53 58
97 93 23
84 62 64
33 83 27
0
 

Sample Output
Case 1: maximum height = 40
Case 2: maximum height = 21
Case 3: maximum height = 28
Case 4: maximum height = 342
*/
/*
*/
#include<stdio.h>
#include<algorithm>
using namespace std;
int cmp(const void *a,const void *b)
{
	return  ((int *)b)[0]*((int *)b)[1]-((int *)a)[0]*((int *)a)[1];//不能return  ((int *)b)[0]-((int *)a)[0];至于为何不能。。。
}
int main()
{
	int len,a,b,c,i,j,most,max,line=1;
	int ss[100][3];
	int hight[100];
	while(scanf("%d",&len),len)
	{
		for(i=0;i<len;i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			ss[3*i][0]=a;ss[3*i][1]=b;ss[3*i][2]=c;
			ss[3*i+1][0]=a;ss[3*i+1][1]=c;ss[3*i+1][2]=b;
			ss[3*i+2][0]=b;ss[3*i+2][1]=c;ss[3*i+2][2]=a;
		}
		memset(hight,0,sizeof(hight));
		qsort(ss,len*3,sizeof(ss[0]),cmp);
	
		most=0;
		for(i=0;i<len*3;i++)
		{
			hight[i]=ss[i][2];
			max=0;
			for(j=0;j<i;j++)
			{
				if(ss[j][0]>ss[i][0]&&ss[j][1]>ss[i][1]||ss[j][0]>ss[i][1]&&ss[j][1]>ss[i][0])
				{
					if(hight[j]>max)max=hight[j];
				}
			}
			if(max)hight[i]=ss[i][2]+max;
			if(hight[i]>most)most=hight[i];
		}
		printf("Case %d: maximum height = %d\n",line++,most);
	}
	return 0;
}