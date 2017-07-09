/*Problem Description
I have a very simple problem for you. Given two integers A and B, your job is to calculate the Sum of A + B.
 

Input
The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. Then T lines follow,
 each line consists of two positive integers, A and B. Notice that the integers are very large, that means you should not 
 process them by using 32-bit integer. You may assume the length of each integer will not exceed 1000.
 

Output
For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case. 
The second line is the an equation "A + B = Sum", Sum means the result of A + B. Note there are some spaces int the equation.
 Output a blank line between two test cases.
 

Sample Input
2
1 2
112233445566778899 998877665544332211
 

Sample Output
Case 1:
1 + 2 = 3

Case 2:
112233445566778899 + 998877665544332211 = 1111111111111111110
*/
#include<stdio.h>
#include<string.h>
int main()
{
    char sa[1001],sb[1001];	
	int len_a,len_b,line,i,j,len;
	char ans[20][3][1002];
	scanf("%d",&line);
	for(i=0;i<line;i++)
	{
		int a[1001]={0},b[1001]={0};
		scanf("%s",sa);
		scanf("%s",sb);
		strcpy(ans[i][0],sa);
		strcpy(ans[i][1],sb);
		len_a=strlen(sa);
		len_b=strlen(sb);
		for(j=len_a-1;j>=0;j--)a[len_a-1-j]=sa[j]-'0';
		for(j=len_b-1;j>=0;j--)b[len_b-1-j]=sb[j]-'0';
        len=len_a>len_b?len_a:len_b;
		for(j=0;j<len;j++)
		{
			a[j]+=b[j];
			a[j+1]+=a[j]/10;
			a[j]=a[j]%10;
		}   
		if(a[len])
		{
			
			for(j=len;j>=0;j--)ans[i][2][len-j]=a[j]+'0';
			ans[i][2][len+1]='\0';
		}
		else
		{
			for(j=len-1;j>=0;j--)ans[i][2][len-1-j]=a[j]+'0';
            ans[i][2][len]='\0';
		}
	}
    for(i=0;i<line;i++)
	{
		printf("Case %d:\n",i+1);
		printf("%s + %s = %s\n",ans[i][0],ans[i][1],ans[i][2]);
		if(i!=(line-1))printf("\n");
	}
	return 0;
}
