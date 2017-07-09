/*
Sample Input
START
from fiwo
hello difh
mars riwosf
earth fnnvk
like fiiwj
END
START
difh, i'm fiwo riwosf.
i fiiwj fnnvk!
END
 

Sample Output
hello, i'm from mars.
i like earth!

*/
/*

*/
#include<stdio.h>
#include<stack>
#include<math.h>
using namespace std;
int main()
{
	int T;
	char e;
	scanf("%d",&T);
	getchar();
	while(T--)
	{
		stack<char> S;//S����������ÿ�ζ����
		while(1)
		{
			scanf("%c",&e);
			if(e=='\n')break;
			if(S.empty())
			{
				S.push(e);
				continue;
			}
			if(S.top()-e<=2&&S.top()-e>=-2)S.pop();
			else S.push(e);
		}
		if(S.empty())printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}