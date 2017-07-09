/*涉及颇多的数论知识
一个数除了2，3，5，7没有其他的素数因子则该数不断整除2 3 5 7必然最终得一，任何合数都可以表示为素数相乘
即：问题需要经过分析，思考才能得出可行（可编程）方案
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
	for(i=1;i<=2000000000;i++)//这一方法理论上是可行的，但是可惜超时，这是把从1~2000000000这些数中，通过“一个个对2 3 5 7整除”判断得来的。
	{                        //但是应该另一个角度，直接把这些数“humble number”从小到大生成，直到2000000000为止。
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
初看此题，题目要求我们解决两个问题：
1、是第几的问题，求出数组，数组的第几个数该如何表达，这用到英文知识：
一般来说个位数是1为st，个位数为2是nd，个位数为3是rd；但是有例外，11， 12 ，13均为th，同时111，112，113均为th，
除此之外，其他都是th；
2、就是求所要求的一个数组（至于为什么是数组，要想不超时，就把所有数据先弄出来，输什么就出第几个就是了，不用重复计算），
题目中列举出前20个，这些数的特点是只能被1、2、3、5、7整除不能被其他素数整除，所以就可以换一个角度思考，所有的数都是
2、3、5、7的2 3 5 7倍，不就可以了
#include<stdio.h>
int humble[6000];//最大2000000000 int足以
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
    for(i=2;i<6000;i++)//精妙绝对的精妙，首先，把倍数分开为a1,a2,a3,a4分别代表2,3,5,7的倍数，这样使得顺序的产生第1 2 3 4……个humble number成为可能，
		              //我当时想的时候是一个公倍数i。其次，a1,a2,a3,a4并不是直接的倍数，而是humble[1]的下标。
    {                 //试想所有humble[]都是有2 3 5 7这4个素数的互相倍数，则bumble[]肯定是题目的要求，这两个表述形式是等价的。
        e1=humble[a1]*2;
        e2=humble[a2]*3;
        e3=humble[a3]*5;
        e4=humble[a4]*7;
        humble[i]=_min(e1,e2,e3,e4);
        if(humble[i]==e1)//这几个连续的if还不能用if else因为可能出现重复的情况即ei=ej,凡是用过ei都不能再用了，既需要将相应的ai++
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
