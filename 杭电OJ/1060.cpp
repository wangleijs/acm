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
/*����˼·��

          1����M=N^N�� 

          2���ֱ�Ե�ʽ����ȡ������ log10(M)=N*log10(N),��M=10^(N*log10(N))��                  

          3����N*log10(N)=a+b,aΪ������bΪС����

          4��C������log10()�����������pow(a,b)����a^b

          5������10���κ�����������λһ��Ϊ1,����,M����λֻ��N*log10(N)��С�������йأ�

          ��ֻ����10^b�ȿ����ˣ�

          6������10^bȡ�������ȡ��������������ˡ�����Ϊ0<=b<1,����1<=10^b<10��

        ��ȡ������ô�ĵ��ľ���һ����λ��Ҳ���������������

���w�˺ü��Σ��ؼ�������n�ǳ������ˡ�
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
