/*
2
5.000000 5.000000
0.000000 0.000000
10.000000 0.000000
10.000000 10.000000
1.000000 1.000000
14.000000 8.222222 

Sample Output
33.33
40.69
*/
/*
*/
#include<stdio.h>
int main()
{
	double a,b,c,k,h,x1,x2,x3,y1,y2,y3,s;
	int line;
	scanf("%d",&line);
	while(line--)
	{
		scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
		a=(y2-y1)/((x2-x1)*(x2-x1));
		b=-2*a*x1;
		c=(y1*4*a+b*b)/(4*a);
		k=(y2-y3)/(x2-x3);
		h=y2-k*x2;
		s=a/3*(x3*x3*x3-x2*x2*x2)+(b-k)/2*(x3*x3-x2*x2)+(c-h)*(x3-x2);//定积分公式
		printf("%.2f\n",s);
	}
	return 0;
}