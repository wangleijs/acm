/*
Problem Description
FatMouse prepared M pounds of cat food, ready to trade with the cats guarding the warehouse containing his favorite food, 
JavaBean.
The warehouse has N rooms. The i-th room contains J[i] pounds of JavaBeans and requires F[i] pounds of cat food. 
FatMouse does not have to trade for all the JavaBeans in the room, instead, he may get J[i]* a% pounds of JavaBeans 
if he pays F[i]* a% pounds of cat food. Here a is a real number. Now he is assigning this homework to you: 
tell him the maximum amount of JavaBeans he can obtain.
 

Input
The input consists of multiple test cases. Each test case begins with a line containing two non-negative integers M and N. 
Then N lines follow, each contains two non-negative integers J[i] and F[i] respectively. The last test case is followed by
 two -1's. All integers are not greater than 1000.
 

Output
For each test case, print in a single line a real number accurate up to 3 decimal places, which is the maximum amount of JavaBeans
 that FatMouse can obtain.
 Sample Input
5 3
7 2
4 3
5 2
20 3
25 18
24 15
15 10
-1 -1
 

Sample Output
13.333
31.500
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int n,i,j,p;
	float m;
	float sum;
	float J[1000],F[1000];
	double ss[1000];
	while(1)
	{
		scanf("%f %d",&m,&n);
    	sum=0.0;
		if(m==-1&&n==-1)break;
		for(i=0;i<n;i++)
		{
			scanf("%f %f",J+i,F+i);
		    /*if(F[i]==0.0)
			{
				ss[i]=-1.0;
                sum+=J[i];
			}
			else */ss[i]=J[i]/F[i];
		}
		for(i=0;i<n;i++)
		{
			p=0;
			for(j=1;j<n;j++)if(ss[j]>ss[p])p=j;
			if(ss[p]>0.0)
			{
				if(m>=F[p])
			{
				sum+=J[p];
				m-=F[p];
			}
			else 
			{
				sum+=m*ss[p];
				break;
			}
			}
		    
			ss[p]=-1.0;
		}
		printf("%.3f\n",sum);
	}
	return 0;
}
