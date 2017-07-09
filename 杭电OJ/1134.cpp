#include<stdio.h>
int main()
{
	int ans[101][1000]={0};
	int len,i,j,t,r,n;
	for(i=0;i<101;i++)
		for(j=0;j<1000;j++)ans[i][j]=0;
		
	r=0;ans[1][0]=1;len=1;//len存放i-1的对应的卡特兰数的长度,r存放进位，或余位
	for(i=2;i<101;i++)//先算大数乘，后算大数除；直接按照公式算a(n)=((4*n-2)/(n+1))*a(n-1)，虽然避免了大数除但是产生了小数
	{
		for(j=0;j<len;j++)ans[i][j]=ans[i-1][j]*(4*i-2);
		for(j=0;j<len;j++) //对乘出的结果进行处理，不包括最高位
		{
			t=ans[i][j]+r;
			ans[i][j]=t%10;//每一个元素设置且只设置一次
			r=t/10;
		}
		while(r)
		{
			ans[i][len]=r%10;
			r=r/10;
			len++;
		}
		r=0;//以下除法部分
		for(j=len-1;j>=0;j--)
		{
			t=ans[i][j]+r*10;
			ans[i][j]=t/(i+1);
			r=t%(i+1);
		}
		while(!(ans[i][len-1]))len--;
	}
	while(scanf("%d",&n)&&n!=-1)
	{
		len=999;
		while(!ans[n][len])len--;
        for(i=len;i>=0;i--)printf("%d",ans[n][i]);
		printf("\n");
	}
	return 0;
}