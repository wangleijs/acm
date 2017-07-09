/*
样例输入 
1
500 3
150 300
100 200
470 471
样例输出 
298
*/
/*
*/
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
	int T,i,L,n,a,b,s;
	char ss[10001];
	scanf("%d",&T);
	while(T--)
	{
		memset(ss,0,sizeof(ss));
		scanf("%d %d",&L,&n);
		memset(ss,1,L+1);//值得看的是memset在这里用的比较“精准”
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&a,&b);
			memset(ss+a,0,b-a+1);
		}
		s=0;
		for(i=0;i<10001;i++)if(ss[i])s++;
		printf("%d\n",s);
	}
	return 0;
}
