#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int i,j;
	int size[9][9];
	int pi[9]={0,3,1,2,7,4,8,5,6};
	//���ݵ��ƹ�ʽ���㹹��size��ֵ�����Ž��ֵ 
	for(j=0;j<pi[1];j++)size[1][j]=0;
	for(j=pi[1];j<9;j++)size[1][j]=1;
	for(i=2;i<8;i++)
	{
		for(j=0;j<pi[i];j++)size[i][j]=size[i-1][j];
		for(j=pi[i];j<9;j++)size[i][j]=max(size[i-1][j],size[i-1][pi[i]-1]+1);
	}
	size[8][8]=max(size[7][8],size[7][pi[8]-1]+1);
	//����size�������ŵĽ������ 
	int ans[8];
	int p=0;
	j=i=8;
	for(;i>1;i--)if(size[i][j]!=size[i-1][j])
	{
		ans[p++]=i;
		j=pi[i]-1;
	}
	if(pi[1]<=j)ans[p++]=1;
	printf("����ཻ�Ӽ���СΪ�� %d\n��ӵ�еĽ��������Ϊ��\n",p);
	for(i=p-1;i>=0;i--)printf("%d----%d\n",ans[i],pi[ans[i]]);
	return 0;
}
