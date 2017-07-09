#include<stdio.h>
#include<string.h>
char ss[21];
int len;
int check1()
{
	int i,p=0;
	for(i=0;i<len;i++)if(ss[i]=='a'||ss[i]=='e'||ss[i]=='i'||ss[i]=='o'||ss[i]=='u')p=1;
	return p;
}
int check2()
{
	int is[20]={0};
	int i,t,p=1;
	for(i=0;i<len;i++)if(ss[i]=='a'||ss[i]=='e'||ss[i]=='i'||ss[i]=='o'||ss[i]=='u')is[i]=1;
	for(i=0;i<len-2;i++)
	{
		t=is[i]+is[i+1]+is[i+2];
		if(t==3||t==0)p=0;
	}
	return p;
}
int check3()
{
	int i,p=1;
	for(i=0;i<len-1;i++)
	{
		if(ss[i]==ss[i+1]&&ss[i]!='e'&&ss[i]!='o')p=0;
	}
	return p;
}
int main()
{
	char end[4]="end";
	while(1)
	{
		int a,b,c;
		gets(ss);
		if(!strcmp(ss,end))break;
		len=strlen(ss);
		a=check1();
		b=check2();
		c=check3();
		if(a*b*c)printf("<%s> is acceptable.\n",ss);
		else printf("<%s> is not acceptable.\n",ss);
	}
}