/*Sample Input
1 0 1 2 0 0
1 0 0 0 1 1
0 0 0 0 0 0
 

Sample Output
Collection #1:
Can't be divided.

Collection #2:
Can be divided.
*/
#include<stdio.h>
int a[7];
int b[7];
int N,flage;
void Backup(int i,int n)
{
//	printf("%d %d\n",i,n);
	int j,sum=0;
	b[i]=n;
	if(i==6)
	{
		for(j=1;j<7;j++)sum+=b[j]*j;
		if(sum==N)flage=1;
		return;
	}
	sum=0;
	for(j=1;j<=i;j++)sum+=b[j]*j;
	if(sum>N)return;//ºÙ÷¶
	for(j=0;j<=a[i+1]&&flage!=1;j++)Backup(i+1,j);
}
int main()
{
	int i,line=1;
	while(1)
	{
		N=0;
		for(i=1;i<7;i++)
		{
			scanf("%d",a+i);
			N+=a[i]*i;
		}
	
		if(N==0)break;
		if(N%2!=0)
		{
			printf("Collection #%d:\nCan't be divided.\n\n",line++);
			continue;
		}
		N=N/2;
		flage=0;
	//	printf("adfsadsf\n");
		Backup(0,0);
		if(flage)printf("Collection #%d:\nCan be divided.\n\n",line++);
		else printf("Collection #%d:\nCan't be divided.\n\n",line++);
	}
	return 0;
}