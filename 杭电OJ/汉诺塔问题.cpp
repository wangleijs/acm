#include<stdio.h>
void hanoi(int n,char a,char b,char c)
{
	if(n==0)return ;
	hanoi(n-1,a,c,b);
	printf("%d:%c->%c\n",n,a,b);
	hanoi(n-1,c,b,a);
}
int main()
{
	hanoi(3,'a','b','c');
	return 0;
}
