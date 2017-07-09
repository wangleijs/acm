#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int fun(char sa[],char sb[])
{
	int len_a=strlen(sa),len_b=strlen(sb);
	char arry[2][10000]={0};
	int i,j,k=0;
	int a,b,c,t;
	for(i=0,k=0;i<=len_a;i++,k=(k+1)%2)
	{
		for(j=0;j<=len_b;j++)
		{
			if(i==0)arry[k][j]=j;
			else if(j==0)arry[k][j]=i;
			else
			{
				a=arry[!k][j]+1;
				b=arry[k][j-1]+1;
				if(sa[i-1]==sb[j-1])c=arry[!k][j-1];
				else c=arry[!k][j-1]+1;
				t=b<c?b:c;
				arry[k][j]=a<t?a:t;
			};
		}
	}
   return arry[!k][j-1];
}
int main()
{
	int line,i;
	int ans[100];
    char sa[10000],sb[10000],e;
	scanf("%d",&line);
    e=getchar();
    for(i=0;i<line;i++)
	{
		scanf("%s",sa);
		scanf("%s",sb);
		ans[i]=fun(sa,sb);
	}
	for(i=0;i<line;i++)printf("%d\n",ans[i]);
	return 0;
}
/*我好不容易把这个程序编好了，然后又好不容易才发现int arry【10000】【10000】数组不能定义，估计占用空间太大，
(如果定义char arryp[1000][1000]程序运行成功)
 
我想定义个100个char arry【1000】【1000】的数组，拼接为一个char arry【10000】【10000】，但是太麻烦几乎不可能；
应该是对最优子结构进行改进吧；
或者是用动态开辟空间的方法，开辟len-a*len-b个int的空间，但是题目要求每行字符串长度《10000；并且它的测试的数据也可能接近10000啊，
这该如何是好？*/