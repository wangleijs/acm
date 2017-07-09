/*
Problem Description
Given a positive integer N, you should output the most right digit of N^N.
 

Input
The input contains several test cases. The first line of the input is a single integer T which is the number of test cases. T test cases follow.
Each test case contains a single positive integer N(1<=N<=1,000,000,000).
 

Output
For each test case, you should output the rightmost digit of N^N.
 

Sample Input
2
3
4
 

Sample Output
7
6
*/
/*这最后一个数只是最后个位数反复相乘的结果，而这结果只在0与9之间，我们只要计算出它的循环
长度即可。
*/
#include<stdio.h>
#include<math.h>
int main()
{
	double a,sum=0.0;
	for(int i=0;i<12;i++)
	{
		scanf("%lf",&a);
		sum+=a;
	}
	sum=sum/12.0;
	printf("$%.2f",sum);
       return 0;
}
