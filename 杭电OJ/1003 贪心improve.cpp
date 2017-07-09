/*Sample Input
2
5 6 -1 5 4 -7
7 0 6 -1 1 -6 7 -5
 

Sample Output
Case 1:
14 1 4

Case 2:
7 1 6*/
#include<stdio.h>
int main()
{
	int ans[20][3];
	int n_case,n_integer;
	int MaxSum,len,fin;
	int temp_MaxSum,l,f;
	int i,j;
	int temp;
	scanf("%d",&n_case);
	for(i=0;i<n_case;i++)
	{
		scanf("%d",&n_integer);
		MaxSum=-1000*100000;
	    temp_MaxSum=l=0;
	    for(j=0;j<n_integer;j++)
		{

		   scanf("%d",&temp);
		   temp_MaxSum+=temp;
		   l++;
		   if(temp_MaxSum>MaxSum)
		   {
			MaxSum=temp_MaxSum;
			len=l;
			fin=j;
		   }
		   if(temp_MaxSum<0)temp_MaxSum=l=0;
		}
		ans[i][0]=MaxSum;ans[i][1]=fin-len+2;ans[i][2]=fin+1;

	}
	for(i=0;i<n_case;i++)
	{
		printf("Case %d:\n",i+1);
		printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
		if(i!=n_case-1)printf("\n");
	}
	return 0;

}