/*
Sample Input
3
olleh !dlrow
m'I morf .udh
I ekil .mca
 

Sample Output
hello world!
I'm from hdu.
I like acm.
*/
#include<stdio.h>
#include<string.h>
int main()
{
	char ss[10000];
	int N,i;
	scanf("%d",&N);
	getchar();
	while(N--)
	{
		
		for(i=0;scanf("%c",&ss[i]);i++)
		{
			if(ss[i]==' ')
			{
				for(i--;i>=0;i--)printf("%c",ss[i]);
				printf(" ");

			}
			else if(ss[i]=='\n')
			{
				for(i--;i>=0;i--)printf("%c",ss[i]);
				printf("\n");
				break;
			}
		}
	}
	return 0;
}