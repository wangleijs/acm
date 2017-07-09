/*
Problem Description
Given a positive integer N, you should output the leftmost digit of N^N.
 

Input
The input contains several test cases. The first line of the input is a single integer T which is the number of test cases.
 T test cases follow.
Each test case contains a single positive integer N(1<=N<=1,000,000,000).
 

Output
For each test case, you should output the leftmost digit of N^N.
 

Sample Input
2
3
4
 

Sample Output
2
2
*/
/*解题思路：

          1，令M=N^N； 

          2，分别对等式两边取对数得 log10(M)=N*log10(N),得M=10^(N*log10(N))；                  

          3，令N*log10(N)=a+b,a为整数，b为小数；

          4，C函数：log10()，计算对数，pow(a,b)计算a^b

          5，由于10的任何整数次幂首位一定为1,所以,M的首位只和N*log10(N)的小数部分有关，

          即只用求10^b救可以了；

          6，最后对10^b取整，输出取整的这个数就行了。（因为0<=b<1,所以1<=10^b<10对

        其取整，那么的到的就是一个个位，也就是所求的数）。

起初w了好几次，关键是忘记n是长整型了。
*/
#include<stdio.h>
#include<math.h>
int main()
{
	int line,n,ans;
	double a,b;
	scanf("%line",&line);
	while(line--)
	{
		scanf("%d",&n);
		a=n*log10(1.0*n);
		b=(_int64)a;
		a=a-b;
		ans=(int)pow(10.0,a);
		printf("%d\n",ans);
	}
       return 0;
}
