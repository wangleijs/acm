#include<stdio.h>
#include<string.h>
char ss[1001][1000];
void fun(char *ans,char *p,char *q)
{
	int r,t,i,len_a,len_p=strlen(p),len_q=strlen(q);
	for(i=0;i<len_q;i++)ans[i]=(q[i]-'0')*2;
	len_a=len_q;//printf("len_p=%d  len_q=%d  hah\n",len_p,len_q);
	for(i=0;i<len_a&&i<len_p;i++)
	{
		
		ans[i]+=(p[i]-'0');
	}
	while(i<len_p)
	{
		ans[i]=p[i]-'0';
		i++;
	}
	len_a=i;
	for(r=0,i=0;i<len_a;i++)
	{
		t=r+ans[i];
		ans[i]=t%10;
		r=t/10;
	}
	while(r)
	{
		ans[len_a]=r%10;
		r=r/10;
		len_a++;
	}
	ans[len_a]='\0';
	for(i=0;i<len_a;i++)ans[i]+='0';
//	printf("%s\n",ans);
}
int main()
{
	int i,n,len;
//	printf("%d\n",'\0');注意'\0'的ASCII码就是0，又像利用char的函数，又像利用%d的时候要弄清楚
	ss[1][0]='0';ss[1][1]='\0';
	ss[2][0]='1';ss[2][1]='\0';
	for(i=3;i<1001;i++)
	{
		fun(ss[i],ss[i-1],ss[i-2]);
	}
	while(scanf("%d",&n)!=EOF)
	{
		len=strlen(ss[n]);
		for(i=len-1;i>=0;i--)printf("%c",ss[n][i]);
		printf("\n");
	}	
	return 0;
}