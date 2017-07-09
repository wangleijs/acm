/*
Sample Input
2
2
Yili 10 500
Mengniu 20 1000
4
Yili 10 500
Mengniu 20 1000
Guangming 1 199
Yanpai 40 10000
 

Sample Output
Mengniu
Mengniu

*/
/*
*/
#include<stdio.h>
#include<string.h>
typedef struct 
{
	char name[11];
	int price,volume;
	double pd;
}MILE;
int main()
{
	int line,n,i,p,t;
	MILE ss[100];
	scanf("%d",&line);
	getchar();
	while(line--)
	{
		scanf("%d",&n);
		getchar();
		for(i=0;i<n;i++)
		{
			scanf("%s",ss[i].name);
			scanf("%d %d",&ss[i].price,&ss[i].volume);
			getchar();
			t=ss[i].volume/200;
			if(t==0){ss[i].pd=1000000000000000000.0;continue;}
			else if(t>5)t=5;
			ss[i].pd=ss[i].price/t;

		}
		p=0;
		for(i=1;i<n;i++)
		{
			if(ss[i].pd<ss[p].pd)p=i;
			else if((ss[i].pd==ss[p].pd)&&ss[i].volume>ss[p].volume)p=i;
		}
		printf("%s\n",ss[p].name);
	}

	return 0;
}