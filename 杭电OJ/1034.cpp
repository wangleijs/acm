/*Problem Description
A number of students sit in a circle facing their teacher in the center. Each student initially has an even number of pieces of candy. When the teacher blows a whistle, each student simultaneously gives half of his or her candy to the neighbor on the right. Any student, who ends up with an odd number of pieces of candy, is given another piece by the teacher. The game ends when all students have the same number of pieces of candy.
Write a program which determines the number of times the teacher blows the whistle and the final number of pieces of candy for each student from the amount of candy each child starts with.


Input
The input may describe more than one game. For each game, the input begins with the number N of students, followed by N (even) candy counts for the children counter-clockwise around the circle. The input ends with a student count of 0. Each input number is on a line by itself.


Output
For each game, output the number of rounds of the game followed by the amount of candy each child ends up with, both on one line.


Sample Input
6
36
2
2
2
2
2
11
22
20
18
16
14
12
10
8
6
4
2
4
2
4
6
8
0


Sample Output
15 14
17 22
4 8

Hint

The game ends in a finite number of steps because:
1. The maximum candy count can never increase.
2. The minimum candy count can never decrease.
3. No one with more than the minimum amount will ever decrease to the minimum.
4. If the maximum and minimum candy count are not the same, at least one student with the minimum amount must have their count increase.
*/
#include<stdio.h>
int main()
{
    int n,i,flage,count,t;
    int ss[100000]={0};
    while(scanf("%d",&n),n)
    {
        for(i=0;i<n;i++)scanf("%d",ss+i);
        count=0;
        while(1)
        {
            for(i=0;i<n;i++)if(ss[i]%2)ss[i]=(ss[i]+1)/2;
                            else ss[i]=ss[i]/2;
							flage=1;
            for(i=0;i<n-1;i++)if(ss[i]!=ss[i+1])flage=0;
            if(flage)break;
            t=ss[n-1];
            for(i=n-1;i>0;i--)ss[i]+=ss[i-1];
            ss[0]+=t;
            count++;
        }
        printf("%d %d\n",count,2*ss[0]);
    }
    return 0;
}
