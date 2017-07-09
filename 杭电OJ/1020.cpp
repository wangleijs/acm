//考虑到数字大于十，考虑到。。
#include<stdio.h>
#include<string.h>
int main()
{
	int line,i,j,k,len,times;
	char e;
	char ss[10002];
	scanf("%d",&line);
	getchar();
	for(i=0;i<line;i++)
	{
		gets(ss);
		len=strlen(ss);
		for(j=0;j<len;j++)
		{
			e=ss[j];
			times=1;
			j++;
			while(e==ss[j])
			{
				times++;
				j++;
			}
			if(times>1)
			printf("%d%c",times,e);
		    else printf("%c",e);
			j--;
		}
		printf("\n");
	}
	return 0;
}
