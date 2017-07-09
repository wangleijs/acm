/*
Input
Each test case will begin with a line containing an integer n(1 ≤ n ≤ 500,000). Then n lines follow.
Each line contains two integers p and r which represents that Poor City p needs to import resources from Rich City r.
 Process to the end of file.


Output
For each test case, output the result in the form of sample.
You should tell JGShining what's the maximal number of road(s) can be built.


Sample Input
2
1 2
2 1
3
1 2
2 3
3 1


Sample Output
Case 1:
My king, at most 1 road can be built.

Case 2:
My king, at most 2 roads can be built.
经典DP算法：最长递增子序列
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	int p,r;
}city;//使用结构体,方便用qsort函数对其进行排序
int cmp(const void *a,const void *b)
{
	return ((city *)a)->p-((city*)b)->p;
}
city data[500000];
int r[500000];
int main()
{
	int N,i,len,e,s,m;
	int line=0;
	while(scanf("%d",&N)!=EOF)
	{
		line++;
		for(i=0;i<N;i++)scanf("%d %d",&data[i].p,&data[i].r);
		qsort(data,N,sizeof(data[0]),cmp);
	    /*s[0]=1;
		for(i=1;i<N;i++)//s[1...n-1]
		{
			w=0;
			for(j=0;j<i;j++)if(data[j].r<data[i].r)
			{
				if(s[j]>w)w=s[j];
			}
			s[i]=w+1;
		}
		w=0;
		for(i=0;i<N;i++)if(s[i]>w)w=s[i];*/
	//	memset(r,0,sizeof(r));
	//	r[0]=-1;
		r[0]=data[0].r;
		len=1;
		for(i=1;i<N;i++)
		{
			s=0;
			e=len-1;
			while(s<=e)
			{
				m=(s+e)/2;
				if(r[m]<data[i].r)s=m+1;
				else e=m-1;
			}
			r[s]=data[i].r;
			if(s>=len)len++;
		}
		if(len==1)printf("Case %d:\nMy king, at most %d road can be built.\n\n",line,len);
		else printf("Case %d:\nMy king, at most %d roads can be built.\n\n",line,len);
	}
	return 0;
}
