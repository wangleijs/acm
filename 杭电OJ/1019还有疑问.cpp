#include<stdio.h>
long LCB(long a,long b)//�����Լ��
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
			a=a/LCB(a,b)*b;//����ĥ��������Сʱ���þ���һ�������ķ���������һ�п��ܵ������û�뵽���������
		}
		printf("%ld\n",a);
	}
	return 0;
}
//�������Ҷ��Ǹ��������ֿ�����д����Լ����������������ϸ��ĥ��
//a=a/LCB(a,b)*b;AC
//a=a*b/LCB(a,b);WA
//a=b/LCB(a,b)*a;AC
//a=b*a/LCB(a,b);WA