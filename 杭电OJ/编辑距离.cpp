#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int fun(char sa[],char sb[])
{
	int len_a=strlen(sa),len_b=strlen(sb);
	char arry[2][10000]={0};
	int i,j,k=0;
	int a,b,c,t;
	for(i=0,k=0;i<=len_a;i++,k=(k+1)%2)
	{
		for(j=0;j<=len_b;j++)
		{
			if(i==0)arry[k][j]=j;
			else if(j==0)arry[k][j]=i;
			else
			{
				a=arry[!k][j]+1;
				b=arry[k][j-1]+1;
				if(sa[i-1]==sb[j-1])c=arry[!k][j-1];
				else c=arry[!k][j-1]+1;
				t=b<c?b:c;
				arry[k][j]=a<t?a:t;
			};
		}
	}
   return arry[!k][j-1];
}
int main()
{
	int line,i;
	int ans[100];
    char sa[10000],sb[10000],e;
	scanf("%d",&line);
    e=getchar();
    for(i=0;i<line;i++)
	{
		scanf("%s",sa);
		scanf("%s",sb);
		ans[i]=fun(sa,sb);
	}
	for(i=0;i<line;i++)printf("%d\n",ans[i]);
	return 0;
}
/*�Һò����װ�����������ˣ�Ȼ���ֺò����ײŷ���int arry��10000����10000�����鲻�ܶ��壬����ռ�ÿռ�̫��
(�������char arryp[1000][1000]�������гɹ�)
 
���붨���100��char arry��1000����1000�������飬ƴ��Ϊһ��char arry��10000����10000��������̫�鷳���������ܣ�
Ӧ���Ƕ������ӽṹ���иĽ��ɣ�
�������ö�̬���ٿռ�ķ���������len-a*len-b��int�Ŀռ䣬������ĿҪ��ÿ���ַ������ȡ�10000���������Ĳ��Ե�����Ҳ���ܽӽ�10000����
�������Ǻã�*/