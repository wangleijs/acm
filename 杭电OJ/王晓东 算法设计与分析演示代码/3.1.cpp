#include<stdio.h>
void matrixChain(int p[],int m[][7],int s[][7],int len)
{
	int r,i,j,k,t;
	for(i=1;i<=len;i++)m[i][i]=0;
	for(r=2;r<=len;r++)
	for(i=1;i<=len-r+1;i++)
	{
		j=i+r-1;//对应一对（i，j） 
		t=m[i+1][j]+p[i-1]*p[i]*p[j];
		s[i][j]=i;
		for(k=i+1;k<j;k++)
		{
		    int tt = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
			if(t>tt)
			{
				t=tt;
				s[i][j]=k;
			}
			 
		}
		m[i][j]=t;
	}
}
int main()
{
	int p[7]={30,35,15,5,10,20,25};
	int m[7][7];
	int s[7][7];
	matrixChain(p,m,s,6);
	int i,j;
	for(i=1;i<7;i++)
	{
		for(j=1;j<7;j++)printf("%10d ",m[i][j]);
		printf("\n");
	}
	for(i=1;i<7;i++)
	{
		for(j=1;j<7;j++)printf("%10d ",s[i][j]);
		printf("\n");
	}
	return 0;
}
