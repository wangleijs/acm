/*
Sample Input
4
START
1 + 2 = 3
END
START
1+2=3
END
START
1 + 2 = 3
END
START
1 + 2 = 3

END
START
1 + 2 = 3
END
START
1 + 2 = 4
END
START
1 + 2 = 3
END
START
1	+	2	=	3
END
 

Sample Output
Presentation Error
Presentation Error
Wrong Answer
Presentation Error
*/
#include<stdio.h>
#include<string.h>
int main()
{
	char sa[500000],sb[500000],s1[10000];
	int N,lena,lenb,i,j,flage;
	scanf("%d",&N);
	getchar();
	while(N--)
	{
		gets(s1);
	    for(i=0;;i++)
		{
			scanf("%c",sa+i);
			if(i>2)
			{
				if(sa[i]=='D'&&sa[i-1]=='N'&&sa[i-2]=='E'&&sa[i-3]=='\n')break;//需要sa[i-3]=='\n'项，否则错误
			}
		}
		sa[i-3]='\0';//sa
		getchar();
		gets(s1);
		for(i=0;;i++)
		{
			scanf("%c",sb+i);
			if(i>2)
			{
				if(sb[i]=='D'&&sb[i-1]=='N'&&sb[i-2]=='E'&&sb[i-3]=='\n')break;//同上
			}
		}
		sb[i-3]='\0';
		getchar();
		lena=strlen(sa);
		lenb=strlen(sb);
	//	printf("%s\n",sa);
	//	printf("%s\n",sb);
		if(strcmp(sa,sb)==0)
		{
			printf("Accepted\n");
			continue;
		}
		flage=1;
	    for(i=0,j=0;i<lena,j<lenb;i++,j++)
		{
			for(;sa[i]==' '||sa[i]=='\n'||sa[i]=='\t';i++);
			for(;sb[j]==' '||sb[j]=='\n'||sb[j]=='\t';j++);
			if(sa[i]!=sb[j])
				{
					flage=0;
					break;
				}
		}
		while(i<lena)
		{
			if(sa[i]==' '||sa[i]=='\n'||sa[i]=='\t')continue;
			else 
			{
				flage=0;
				break;
			}
		}
		while(j<lenb)
		{
			if(sb[j]==' '||sb[j]=='\n'||sb[j]=='\t')continue;
			{
				flage=0;
				break;
			}
		}
		if(flage==0)printf("Wrong Answer\n");
		else printf("Presentation Error\n");
	}
	return 0;
}