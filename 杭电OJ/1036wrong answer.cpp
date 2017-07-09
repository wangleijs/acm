/*2 12.5
  5 0:23:21 0:25:01
 42 0:23:32 -:--:--
  7 0:33:20 0:41:35
 

Sample Output
  5: 3:52 min/km
 42: -
  7: 6:00 min/km*/
#include<stdio.h>
int main()
{
	int n,i;
	double dis;
	while(scanf("%d %lf",&n,&dis)!=EOF)//”√%lf ‰»Îdis
	{
		int num,h=0,min=0,sec=0;
		double x,y;
		char a,b,c,d,e;
		int ans_m,ans_s;
		while(scanf("%3d",&num)!=EOF)
		{
			h=0,min=0,sec=0;
			for(i=0;i<n;i++)
			{
				scanf(" %c:%c%c:%c%c",&a,&b,&c,&d,&e);
				if(a=='-')break;
				h+=(a-'0');
				min+=((b-'0')*10+(c-'0'));
				sec+=((d-'0')*10+(e-'0'));
			}
			if(i!=n)
			{
				printf("%3d: -\n",num);
				continue;
			}	
			x=h*3600+min*60+sec;
			y=x/dis;
			if(y-(int)y>=0.5)y=(int)y+1.0;
			else y=(int)y;
     		ans_m=y/60;
			ans_s=y-ans_m*60;
			if(ans_s<10) printf("%3d: %d:0%d min/km\n",num,ans_m,ans_s);
			else printf("%3d: %d:%d min/km\n",num,ans_m,ans_s);
		}

	}
	return 0;
}