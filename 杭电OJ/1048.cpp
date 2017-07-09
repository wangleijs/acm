/*
Sample Input
START
NS BFW, JAJSYX TK NRUTWYFSHJ FWJ YMJ WJXZQY TK YWNANFQ HFZXJX
END
START
N BTZQI WFYMJW GJ KNWXY NS F QNYYQJ NGJWNFS ANQQFLJ YMFS XJHTSI NS WTRJ
END
START
IFSLJW PSTBX KZQQ BJQQ YMFY HFJXFW NX RTWJ IFSLJWTZX YMFS MJ
END
ENDOFINPUT
 

Sample Output
IN WAR, EVENTS OF IMPORTANCE ARE THE RESULT OF TRIVIAL CAUSES
I WOULD RATHER BE FIRST IN A LITTLE IBERIAN VILLAGE THAN SECOND IN ROME
DANGER KNOWS FULL WELL THAT CAESAR IS MORE DANGEROUS THAN HE
*/
#include<stdio.h>
#include<string.h>
int main()
{
	char * s1="START",* s2="END",* s3="ENDOFINPUT";
	char e;
	char ss[1000000];
	int i,t;
	while(gets(ss))
	{
		if(strcmp(ss,s1)==0||strcmp(ss,s2)==0)continue;
		else if(strcmp(ss,s3)==0)break;
		for(i=0;ss[i]!='\0';i++)
		{
			e=ss[i];
			if(e<'A'||e>'Z')
			{
				printf("%c",e);
				continue;
			}
			t=(e-'A'-5+26)%26;
			e='A'+t;
			printf("%c",e);
		}
		printf("\n");
	}
	return 0;
}