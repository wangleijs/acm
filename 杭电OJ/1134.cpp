#include<stdio.h>
int main()
{
	int ans[101][1000]={0};
	int len,i,j,t,r,n;
	for(i=0;i<101;i++)
		for(j=0;j<1000;j++)ans[i][j]=0;
		
	r=0;ans[1][0]=1;len=1;//len���i-1�Ķ�Ӧ�Ŀ��������ĳ���,r��Ž�λ������λ
	for(i=2;i<101;i++)//��������ˣ������������ֱ�Ӱ��չ�ʽ��a(n)=((4*n-2)/(n+1))*a(n-1)����Ȼ�����˴��������ǲ�����С��
	{
		for(j=0;j<len;j++)ans[i][j]=ans[i-1][j]*(4*i-2);
		for(j=0;j<len;j++) //�Գ˳��Ľ�����д������������λ
		{
			t=ans[i][j]+r;
			ans[i][j]=t%10;//ÿһ��Ԫ��������ֻ����һ��
			r=t/10;
		}
		while(r)
		{
			ans[i][len]=r%10;
			r=r/10;
			len++;
		}
		r=0;//���³�������
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