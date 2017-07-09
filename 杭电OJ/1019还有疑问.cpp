#include<stdio.h>
long LCB(long a,long b)//求最大公约数
{
	long r;
	if(a<b)
	{
		r=a;
		a=b;
		b=r;
	}
	while(b)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int main()
{
	int line,n,i;
	long a,b;
	scanf("%d",&line);
	while(line--)
	{
        i=0;
		scanf("%d",&n);
		scanf("%ld",&a);
		while(--n)
		{
			scanf("%ld",&b);
			a=a/LCB(a,b)*b;//我琢磨了两个多小时，用尽了一切想得起的方法，考虑一切可能的情况，没想到是这个问题
		}
		printf("%ld\n",a);
	}
	return 0;
}
//以下是我对那个话的四种可能书写情况以及ＡＣ与否的情况，仔细琢磨，
//a=a/LCB(a,b)*b;AC
//a=a*b/LCB(a,b);WA
//a=b/LCB(a,b)*a;AC
//a=b*a/LCB(a,b);WA