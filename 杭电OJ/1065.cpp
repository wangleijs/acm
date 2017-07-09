/*
Sample Input
2 
1.0 1.0 
25.0 0.0
 

Sample Output
Property 1: This property will begin eroding in year 1. 
Property 2: This property will begin eroding in year 20. 
END OF OUTPUT. 
*/
/*
*/
#include<stdio.h>
#include<math.h>
int main()
{
	int line,i,year;
	double x,y,r;
	scanf("%d",&line);
	if(line==0)return 0;
	for(i=1;i<=line;i++)
	{
		scanf("%lf %lf",&x,&y);
		r=(3.1415926 * (x*x+y*y));
		year=(int)(r/100);//注意这里不能写成(int)r/100,
		printf("Property %d: This property will begin eroding in year %d.\n",i,year+1);
	}
	printf("END OF OUTPUT.\n"); 
       return 0;
}
