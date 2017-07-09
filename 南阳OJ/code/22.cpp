/*
样例输入 
3
5
1 2 3 4 5
8
11 12 13 14 15 16 17 18
10
21 22 23 24 25 26 27 28 29 30
样例输出 
10
41
52

*/
/*
*/
#include<stdio.h>
#include<math.h>
int main()
{
	int T,N,i,j,s,is;
	int ss[1000];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(i=0;i<N;i++)scanf("%d",ss+i);
		s=0;
		for(i=0;i<N;i++)//判断ss[i]是否为素数
		{
			if(ss[i]<=1)continue;
			is=1;
			for(j=2;j<=(int)sqrt(ss[i]);j++)if(ss[i]%j==0)is=0;
			if(is)s+=ss[i];
		}
		printf("%d\n",s);
	}
	
	return 0;
}  
