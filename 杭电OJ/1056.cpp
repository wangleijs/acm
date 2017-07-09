/*
Sample Input
1.00
3.71
0.04
5.19
0.00
 

Sample Output
3 card(s)
61 card(s)
1 card(s)
273 card(s)
*/
#include<stdio.h>
int main()
{
	double f,s;
	int i;
	while(scanf("%lf",&f),f)
	{
		s=0.0;
		for(i=1;;i++)
		{
			s+=1.0/(i+1);
			if(s>f)break;
		}
		printf("%d card(s)\n",i);
	}
	return 0;
}