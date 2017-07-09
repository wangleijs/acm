//确实是个水题，本以为会超时，废了九牛二虎之力还是没有找到规律原来，直接暴力求解就可以了，
/*Sample Input
1 10
100 200
201 210
900 1000
 

Sample Output
1 10 20
100 200 125
201 210 89
900 1000 174
 if n is odd then n <- 3n + 1

    5.           else n <- n / 2
*/
#include<stdio.h>
int main()
{
	int n,m,t,i,max,temp;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		printf("%d %d ",n,m);
		if(n>m)
		{
			t=n;
			n=m;
			m=t;
		}
		max=0;
		for(i=n;i<=m;i++)
		{
			t=i;
			temp=1;
			while(t!=1)
			{
				temp++;
				if(t%2)t=3*t+1;
				else t=t/2;
			}
			if(temp>max)max=temp;
		}
		printf("%d\n",max);
	}
	return 0;
}