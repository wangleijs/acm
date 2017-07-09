/*
样例输入 
1
1234
样例输出 
4
*/
/*

#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int ss[1000];
bool is(int p,int len)
{
	int i;
	for(i=0;i<len;i++)if(ss[i]==p)return true;
	return false;
}
int main()
{
	int T,i,min,max,q,j;
	char st[4];
	scanf("%d",&T);
	getchar();
	while(T--)
	{
		memset(ss,0,sizeof(ss));
		gets(st);
		for(i=0;i<4;i++)st[i]=st[i]-'0';
		ss[0]=st[0]*1000+st[1]*100+st[2]*10+st[3];
		for(i=1;;i++)
		{
		   sort(st,st+4);
		   min=st[0]*1000+st[1]*100+st[2]*10+st[3];
		   max=st[3]*1000+st[2]*100+st[1]*10+st[0];
		   q=max-min;
		   printf("fhadjkdfs\n");
		   if(q==ss[i-1])break;
		   ss[i]=q;
		   memset(st,0,sizeof(st));
		   j=0;
		   while(q)
		   {
		   	st[j++]=q%10;
		   	q=q/10;
		   }
		}
		printf("%d\n",i);
	}
	return 0;
}
*/
#include<iostream>
using namespace std;
void sortmin(int a[4],int c[4])
{
int i,j;
for(i=1;i<4;i++)
{
int tmp=a[i];
for(j=i;j>0 && tmp<a[j-1];j--)
a[j]=a[j-1];
a[j]=tmp;
}
for(i=0;i<4;i++)
c[i]=a[i];
}
void sortmax(int a[4],int b[4])
{
int i,j;
for(i=1;i<4;i++)
{
int tmp=a[i];
for(j=i;j>0 && tmp>a[j-1];j--)
a[j]=a[j-1];
a[j]=tmp;
}
for(i=0;i<4;i++)
b[i]=a[i];
}
int main()
{
int N; cin>>N;
while(N--)
{
int a[4],b[4],c[4];
int n,i=0,count=1; cin>>n;
while(n!=6174 && count<30)
{
for(i=0;i<4;i++){
a[i]=n%10;
n=n/10;
}
sortmax(a,b);
sortmin(a,c);
n=(b[0]-c[0])*1000+(b[1]-c[1])*100+(b[2]-c[2])*10+b[3]-c[3];
count++;
}
cout<<count<<endl;
}
return 0;
}//