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
/*�����һ����ֻ������λ��������˵Ľ����������ֻ��0��9֮�䣬����ֻҪ���������ѭ��
���ȼ��ɡ�
*/
#include<stdio.h>
#include<math.h>
int main()
{
	int line,n,a,b,i,len;
	int ss[10];
	scanf("%d",&line);
	while(line--)
	{
		scanf("%d",&n);
		a=n%10;
		ss[0]=b=a;
		for(i=1;;i++)
		{
			b=(b*a)%10;
			if(b==a)break;
			ss[i]=b;
		}
		len=i;
		b=(n-1)%len;
		printf("%d\n",ss[b]);
	}
       return 0;
}
