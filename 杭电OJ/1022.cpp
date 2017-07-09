//起初在考虑从o2->o1的逆向思维这样的思维判断yes/no还可以但记录路径的时候相当的麻烦
//利用递归调用的功能，考虑所有可能情况，但是在back的过程中那些参数很复杂
/*
Train Problem I

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 15907    Accepted Submission(s): 5904


Problem Description
As the new term comes, the Ignatius Train Station is very busy nowadays. A lot of student want to get back to school by train(because the trains in the Ignatius Train Station is the fastest all over the world ^v^). But here comes a problem, there is only one railway where all the trains stop. So all the trains come in from one side and get out from the other side. For this problem, if train A gets into the railway first, and then train B gets into the railway before train A leaves, train A can't leave until train B leaves. The pictures below figure out the problem. Now the problem for you is, there are at most 9 trains in the station, all the trains has an ID(numbered from 1 to n), the trains get into the railway in an order O1, your task is to determine whether the trains can get out in an order O2.

 

Input
The input contains several test cases. Each test case consists of an integer, the number of trains, and two strings, the order of the trains come in:O1, and the order of the trains leave:O2. The input is terminated by the end of file. More details in the Sample Input.
 

Output
The output contains a string "No." if you can't exchange O2 to O1, or you should output a line contains "Yes.", and then output your way in exchanging the order(you should output "in" for a train getting into the railway, and "out" for a train getting out of the railway). Print a line contains "FINISH" after each test case. More details in the Sample Output.
 

Sample Input
3 123 321
3 123 312
 

Sample Output
Yes.
in
in
in
out
out
out
FINISH
No.
FINISH
*/
//考虑各种可能情况，记录opt，
#include<stdio.h>
typedef struct
{
	int top;//
	char data[9];
}stack;
stack s;
void push(char e)
{
	s.data[s.top++]=e;
}
void dele()
{
	s.top--;
}
int main()
{
	int opt[18];
    char o1[10],o2[10];
	int n,p,q,k,flage;
	
	while(scanf("%d %s %s",&n,o1,o2)!=EOF)
	{
		p=q=k=0;
		flage=1;
		s.top=0;
		while(q<n)
		{
			if(p<n)
			{
				if(o1[p]==o2[q])
				{
					opt[k++]=1;
					opt[k++]=0;
					p++;
					q++;
				}
				else if(s.top>0&&s.data[s.top-1]==o2[q])
				{
					dele();
					opt[k++]=0;
					q++;
				}
				else 
				{
					push(o1[p]);
					opt[k++]=1;
					p++;
				}
			}
			else
			{
				if(s.top>0&&s.data[s.top-1]==o2[q])
				{
					dele();
					opt[k++]=0;
					q++;
				}
				else
				{
					flage=0;
					break;
				}
			}

		}
		if(flage)
		{
			printf("Yes.\n");
			for(k=0;k<2*n;k++)opt[k]?printf("in\n"):printf("out\n");
			printf("FINISH\n");
		}
		else 
		{
			printf("No.\nFINISH\n");
		}
	}
	return 0;
}
