#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int i,j,c=10,n=5,jmax;
	int w[6]={0,2,2,6,5,4},v[6]={0,6,3,5,4,6};
	int m[6][c+1]; 
	//根据递推公式计算构造m的值，即最优解的值 
	jmax=min(c,w[n]-1);
	for(j=0;j<=jmax;j++)m[n][j]=0;
	for(j=w[n];j<=c;j++)m[n][j]=v[n];
	for(i=n-1;i>1;i--)
	{
		jmax=min(c,w[i]-1);
		for(j=0;j<=jmax;j++)m[i][j]=m[i+1][j];
		for(j=w[i];j<=c;j++)m[i][j]=max(m[i+1][j],m[i+1][j-w[i]]+v[i]);
	}
	if(w[1]<=c)m[1][c]=max(m[2][c],m[2][c-w[1]]+v[1]);
	else m[1][c]=m[2][c];
	printf("%d\n",m[1][c]);
	//根据m构造最优的解决方案
	int ans[6];
	for(i=1;i<n;i++)
	if(m[i][c]==m[i+1][c])ans[i]=0;
	else 
	{
		ans[i]=1;
		c-=w[i];
	}
	if(m[n][c]>0)ans[n]=1;
	printf("最优的解决方案:\n");
	for(i=1;i<=n;i++)printf("%d ",ans[i]);
	 
	return 0;
}
