/*
���� 
��С�ܵĴʻ�����С������ÿ����Ӣ��ѡ�����ʱ�򶼺�ͷ�ۡ��������ҵ���һ�ַ�����������֤���������ַ���ȥѡ��ѡ���ʱ��ѡ�Եļ��ʷǳ��� 
���ַ����ľ����������£�����maxn�ǵ����г��ִ���������ĸ�ĳ��ִ�����minn�ǵ����г��ִ������ٵ���ĸ�ĳ��ִ��������maxn-minn��һ����������ô��С�ܾ���Ϊ���Ǹ�Lucky Word�������ĵ��ʺܿ��ܾ�����ȷ�Ĵ𰸡� 

���� 
��һ������N(0<N<100)��ʾ��������������
ÿ�������������ֻ��һ�У���һ�����ʣ�����ֻ���ܳ���Сд��ĸ�����ҳ���С��100�� 
��� 
ÿ�����������������У���һ����һ���ַ�������������ĵĵ�����Lucky Word����ô�����Lucky Word�������������No Answer���� 
�ڶ�����һ��������������뵥����Lucky Word�����maxn-minn��ֵ���������0 
�������� 
2
error
olympic
������� 
Lucky Word
2
No Answer
0
*/
/*
bfs
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
bool is(int n)
{
	int i;
	if(n<=1)return false;
	for(i=2;i<=(int)sqrt(n);i++)if(n%i==0)return false;
	return true;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int ss[26]={0};
		char st[100];
		int i,len,max,min;
		scanf("%s",st);
		len=strlen(st);
		for(i=0;i<len;i++)ss[st[i]-'a']++;
		max=0;min=100;
		for(i=0;i<26;i++)if(ss[i])
		{
			if(ss[i]>max)max=ss[i];
			if(ss[i]<min)min=ss[i];
		}
		if(is(max-min))printf("Lucky Word\n%d\n",max-min);
		else printf("No Answer\n0\n");	
	}
	return 0;
}
