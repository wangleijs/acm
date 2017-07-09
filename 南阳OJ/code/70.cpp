/*
描述 
给定两个数n，m,其中m是一个素数。

将n（0<=n<=2^31）的阶乘分解质因数，求其中有多少个m。

注：^为求幂符号。

 

输入 
第一行是一个整数s（0<s<=100)，表示测试数据的组数
随后的s行, 每行有两个整数n，m。 

输出 
输出m的个数

样例输入 
3
100 5
16 2
1000000000  13
样例输出 
24
15
83333329
*/
/*
斯特林公式：lnN!=NlnN-N+0.5*ln(2*N*pi) x
*/
#include<stdio.h>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int s=0,n,m,i,t;
		scanf("%d %d",&n,&m);
		while(n)
		{
			n=n/m;
			s+=n;
		}
		printf("%d\n",s);
	}
	return 0;
}

