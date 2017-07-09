/*
样例输入 
1
14
样例输出 
4
*/
/*
紧下边的是我的runtime error的代码，虽说没有通过，但仍然很有收获：
#include<stdio.h>
#include<math.h>
int ss[100000];
bool is(int a)
{
	int i;
	if(a<=1)return false;
	for(i=2;i<=(int)sqrt(a);i++)if(a%i==0)return false;//只要出现这一情况就返回，这样可以大大的节省时间
	return true;
}//关于素数判断的这段代码很有感触，原开始的是：
/*
bool is(int a)
{
	int i,is=1;
	if(a<=1)return false;
	for(i=2;i<=(int)sqrt(a);i++)if(a%i==0)is=0;
	if(is)return true;
	else return false;
}

*/
/*
int main()
{
	int T,n,i,len,s;
	scanf("%d",&T);
	len=0;
	for(i=2;i<1000000;i++)if(is(i))ss[len++]=i;
	while(T--)
	{
		s=0;
		scanf("%d",&n);
		if(n<=2)
		{
			printf("0\n");
			continue;
		}
		for(i=1;ss[i]<=n;i++)
		{
			if(ss[i]-ss[i-1]==2)s++;
		}
		printf("%d\n",s+1);
	}
	return 0;
}  

#include<stdio.h>
#include<math.h>
int a[1000005];
int main()
{
int is_prime(int n);
int i,j,n;
for(i=2,j=0;i<1000005;i++)
{
if(is_prime(i))
{
a[j]=i;
j++;
}
}
scanf("%d",&n);
while(n--)
{
int m,p,q,count=0;
scanf("%d",&m);
if(m==0||m==1)
{
printf("0\n");
continue;
}
for(i=1;a[i]<=m;i++)
{
if((a[i]-a[i-1]==1)||(a[i]-a[i-1]==2))
count++;

}
printf("%d\n",count);


}
return 0;

}
int is_prime(int n)
{
int flag=0,i;

if(n==1||n<=0)
return 0;
else
{
for(i=2;i<=sqrt(n);i++)
{
if(n%i==0)
{
flag=1;
break;
}

}
if(!flag)
return 1;
else
return 0;
}
}
*/
#include<stdio.h>
#include<math.h>
int find_prime(int d)
{
    int i;
if(d>1){
for(i=2;i<=sqrt(d);i++){
if(d%i==0)return 0;
}
return 1;
}
else return 0;

}

int main(){
int N,n,m,i,j=2;
int prime[100000]={0,2};
for(i=3;i<1000000;i+=2){
if(find_prime(i))prime[j++]=i;
}
scanf("%d",&N);
while(N--){
scanf("%d",&m);
n=0;
for(j=2;prime[j]<=m;j++){
if((prime[j]-prime[j-1])==1||(prime[j]-prime[j-1])==2)n++;
}
printf("%d\n",n);
}
return 0;
}



