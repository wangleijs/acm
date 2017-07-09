/*
描述 
笨小熊的词汇量很小，所以每次做英语选择题的时候都很头疼。但是他找到了一种方法，经试验证明，用这种方法去选择选项的时候选对的几率非常大！ 
这种方法的具体描述如下：假设maxn是单词中出现次数最多的字母的出现次数，minn是单词中出现次数最少的字母的出现次数，如果maxn-minn是一个质数，那么笨小熊就认为这是个Lucky Word，这样的单词很可能就是正确的答案。 

输入 
第一行数据N(0<N<100)表示测试数据组数。
每组测试数据输入只有一行，是一个单词，其中只可能出现小写字母，并且长度小于100。 
输出 
每组测试数据输出共两行，第一行是一个字符串，假设输入的的单词是Lucky Word，那么输出“Lucky Word”，否则输出“No Answer”； 
第二行是一个整数，如果输入单词是Lucky Word，输出maxn-minn的值，否则输出0 
样例输入 
2
error
olympic
样例输出 
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
