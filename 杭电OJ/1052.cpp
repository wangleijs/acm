//贪心策略不对必然是ＷＡ
/*#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n,i,j,t,q;
	int sa[1000],sb[1000];
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)scanf("%d",sa+i);
		for(i=0;i<n;i++)scanf("%d",sb+i);
		sort(sa,sa+n,cmp);
		sort(sb,sb+n,cmp);
		t=0;q=0;
		for(i=n-1,j=n-1;i>=0&&j>=0;)
		{
			for(;sa[i]<sb[j]&&i>=0;i--);
			if(i>=0)
			{	if(sa[i]==sb[j])q++;
		        else t++;
			}
		printf("q=%d t=%d\n",q,t);	
			i--;
			j--;
		}
		t=t*200-(n-t-q)*200;
		printf("%d\n",t);
	}
	return 0;
}*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[1005],b[1005];
int main(int argc, char *argv[])
{     
	int n,m,i,j,k,s;     
	while(cin>>n,n)     
	{         
		for(i=0;i<n;i++)         
			cin>>a[i];         
		for(i=0;i<n;i++)         
			cin>>b[i];         
		sort(a,a+n);  
		sort(b,b+n);         
		j=0;  k=n-1;  s=0;         
		for(i=0;i<n;)         
			if(a[i]>b[j]) s++,j++,i++;         
			else if(a[n-1]>b[k]) s++,n--,k--;         
			else 
			{                 
				if(a[i]<b[k]) s--;                 
				k--;
				i++;              
			}          
			cout<<s*200<<endl;     
	}     
	return 0; 
}