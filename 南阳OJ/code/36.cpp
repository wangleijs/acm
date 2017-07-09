/*
2
asdf
adfsd
123abc
abc123abc
样例输出 
3
6
*/
/*
*/
#include<stdio.h>
#include<string.h>
int ss[1001][1001];
int max(int a,int b,int c)
{
	if(a<b)a=b;
	if(a<c)a=c;
	return a;
}
int main()
{
	int T,i,j;
	char sa[1001],sb[1001];
	int lena,lenb;
	scanf("%d",&T);
	getchar();
	while(T--)
	{
		gets(sa);
		gets(sb);
		lena=strlen(sa);
		lenb=strlen(sb);
		for(i=0;i<=lena;i++)
			for(j=0;j<=lenb;j++)
			{
				if(i==0||j==0)ss[i][j]=0;
				else if(sa[i-1]==sb[j-1])ss[i][j]=max(ss[i-1][j],ss[i][j-1],ss[i-1][j-1]+1);
				else ss[i][j]=max(ss[i-1][j],ss[i][j-1],ss[i-1][j-1]);
				//不能直接省为ss[i][j]=max(ss[i-1][j],ss[i][j-1],ss[i-1][j-1]+sa[i-1]==sb[j-1])
			}
		printf("%d\n",ss[lena][lenb]);
	}
	return 0;
}