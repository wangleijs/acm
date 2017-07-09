/*
样例输入 
3
aaa
ababc
abklmncdefg
样例输出 
1
3
7
*/
/*
*/
#include<stdio.h>
#include<string.h>
int main()
{
	int T,len,i,j;
	char ss[10001];
	int t[10000];//建立一个以ss[i]为结尾的最长递增子序列t[i]
	int e,s;
	scanf("%d",&T);
	getchar();
	while(T--)
	{
		gets(ss);
		len=strlen(ss);
		t[0]=1;s=1;
		for(i=1;i<len;i++)
		{
			e=0;
			for(j=0;j<i;j++)
			{
				if(ss[j]<ss[i]&&t[j]>e)e=t[j];
			}
			t[i]=e+1;
			if(t[i]>s)s=t[i];
		}
		printf("%d\n",s);
	}
	return 0;
}  
