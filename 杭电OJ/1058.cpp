/*�漰�Ķ������֪ʶ
һ��������2��3��5��7û�����������������������������2 3 5 7��Ȼ���յ�һ���κκ��������Ա�ʾΪ�������
����������Ҫ����������˼�����ܵó����У��ɱ�̣�����
Sample Input
1
2
3
4
11
12
13
21
22
23
100
1000
5842
0
 

Sample Output
The 1st humble number is 1.
The 2nd humble number is 2.
The 3rd humble number is 3.
The 4th humble number is 4.
The 11th humble number is 12.
The 12th humble number is 14.
The 13th humble number is 15.
The 21st humble number is 28.
The 22nd humble number is 30.
The 23rd humble number is 32.
The 100th humble number is 450.
The 1000th humble number is 385875.
The 5842nd humble number is 2000000000.
*/
/*
#include<stdio.h>
int main()
{
	int ss[5842];
	int len=0,s,_s,i;
	for(i=1;i<=2000000000;i++)//��һ�����������ǿ��еģ����ǿ�ϧ��ʱ�����ǰѴ�1~2000000000��Щ���У�ͨ����һ������2 3 5 7�������жϵ����ġ�
	{                        //����Ӧ����һ���Ƕȣ�ֱ�Ӱ���Щ����humble number����С�������ɣ�ֱ��2000000000Ϊֹ��
		_s=s=i;
		while(s!=1)
		{
			if(s%2==0)s=s/2;
			if(s%3==0)s=s/3;
			if(s%5==0)s=s/5;
			if(s%7==0)s=s/7;
			if(_s!=s)_s=s;
			else break;
		}
		if(s==1)ss[len++]=i;
	}
	for(i=0;i<20;i++)printf("%d\n",ss[i]);
	int n;
	while(scanf("%d",&n),n)
	{
		if((n-1)/10*10==(n-1))
		{
			if(n==11||n==111)printf("The %dth humble number is %d.",n,ss[n-1]);
			else printf("The %dst humble number is %d.",n,ss[n-1]);
		}
		else if((n-2)/10*10==(n-2))
		{
			if(n==12||n==112)printf("The %dth humble number is %d.",n,ss[n-1]);
			else printf("The %dnd humble number is %d.",n,ss[n-1]);
		}
		else if((n-3)/10*10==(n-3))
		{
			if(n==13||n==113)printf("The %dth humble number is %d.",n,ss[n-1]);
			else printf("The %drd humble number is %d.",n,ss[n-1]);
		}
		else 
		{
			printf("The %dth humble number is %d.",n,ss[n-1]);
		}
	}
	return 0;
}*/
/*
�������⣬��ĿҪ�����ǽ���������⣺
1���ǵڼ������⣬������飬����ĵڼ���������α����õ�Ӣ��֪ʶ��
һ����˵��λ����1Ϊst����λ��Ϊ2��nd����λ��Ϊ3��rd�����������⣬11�� 12 ��13��Ϊth��ͬʱ111��112��113��Ϊth��
����֮�⣬��������th��
2����������Ҫ���һ�����飨����Ϊʲô�����飬Ҫ�벻��ʱ���Ͱ�����������Ū��������ʲô�ͳ��ڼ��������ˣ������ظ����㣩��
��Ŀ���оٳ�ǰ20������Щ�����ص���ֻ�ܱ�1��2��3��5��7�������ܱ������������������ԾͿ��Ի�һ���Ƕ�˼�������е�������
2��3��5��7��2 3 5 7�������Ϳ�����
#include<stdio.h>
int humble[6000];//���2000000000 int����
int a1,a2,a3,a4;
int e1,e2,e3,e4;
int _min(a,b,c,d)
{
    int min;
    if(a<b)
    min=a;
    else
    min=b;
    if(min>c)
    min=c;
    if(min>d)
    min=d;
    return min;
}
int main()
{
    int n,i;
    a1=a2=a3=a4=1;
    humble[1]=1;
    for(i=2;i<6000;i++)//������Եľ�����ȣ��ѱ����ֿ�Ϊa1,a2,a3,a4�ֱ����2,3,5,7�ı���������ʹ��˳��Ĳ�����1 2 3 4������humble number��Ϊ���ܣ�
		              //�ҵ�ʱ���ʱ����һ��������i����Σ�a1,a2,a3,a4������ֱ�ӵı���������humble[1]���±ꡣ
    {                 //��������humble[]������2 3 5 7��4�������Ļ��౶������bumble[]�϶�����Ŀ��Ҫ��������������ʽ�ǵȼ۵ġ�
        e1=humble[a1]*2;
        e2=humble[a2]*3;
        e3=humble[a3]*5;
        e4=humble[a4]*7;
        humble[i]=_min(e1,e2,e3,e4);
        if(humble[i]==e1)//�⼸��������if��������if else��Ϊ���ܳ����ظ��������ei=ej,�����ù�ei�����������ˣ�����Ҫ����Ӧ��ai++
            a1++;
        if(humble[i]==e2)
            a2++;
        if(humble[i]==e3)
            a3++;
        if(humble[i]==e4)
            a4++;
    }
    while(scanf("%d",&n)&& n)
    {
        if(n%100==11)
        printf("The %dth humble number is %d.\n",n,humble[n]);
        else if(n%100==12)
        printf("The %dth humble number is %d.\n",n,humble[n]);
        else if(n%100==13)
        printf("The %dth humble number is %d.\n",n,humble[n]);
        else if(n%10==1)
        printf("The %dst humble number is %d.\n",n,humble[n]);
        else if(n%10==2)
        printf("The %dnd humble number is %d.\n",n,humble[n]);
        else if(n%10==3)
        printf("The %drd humble number is %d.\n",n,humble[n]);
        else
        printf("The %dth humble number is %d.\n",n,humble[n]);
    }
    return 0;
}*/

#include<stdio.h>
int min(int a,int b,int c,int d)
{
	int t=a>b?b:a;
	if(t>c)t=c;
	if(t>d)t=d;
	return t;
}
int main()
{
	int ss[5842];
	int b1,b2,b3,b4,e1,e2,e3,e4,n,i;
	ss[0]=1;
	b1=b2=b3=b4=0;
	for(i=1;i<5842;i++)
	{
		e1=ss[b1]*2;
		e2=ss[b2]*3;
		e3=ss[b3]*5;
		e4=ss[b4]*7;
		ss[i]=min(e1,e2,e3,e4);
		if(ss[i]==e1)b1++;
		if(ss[i]==e2)b2++;
		if(ss[i]==e3)b3++;
		if(ss[i]==e4)b4++;
	}
	while(scanf("%d",&n),n)
	{
		if((n-1)%10==0)
		{
			if((n-11)%100==0||(n-111)%1000==0)printf("The %dth humble number is %d.\n",n,ss[n-1]);
			else printf("The %dst humble number is %d.\n",n,ss[n-1]);
		}
		else if((n-2)%10==0)
		{
			if((n-12)%100==0||(n-112)%1000==0)printf("The %dth humble number is %d.\n",n,ss[n-1]);
			else printf("The %dnd humble number is %d.\n",n,ss[n-1]);
		}
		else if((n-3)%10==0)
		{
			if((n-13)%100==0||(n-113)%1000==0)printf("The %dth humble number is %d.\n",n,ss[n-1]);
			else printf("The %drd humble number is %d.\n",n,ss[n-1]);
		}
		else 
		{
			printf("The %dth humble number is %d.\n",n,ss[n-1]);
		}
	}
	return 0;
}
