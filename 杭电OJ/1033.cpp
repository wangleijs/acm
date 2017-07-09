#include<stdio.h>
#include<string.h>
int main()
{
    int d,x,y,i;
    char e,ss[201];
    while(gets(ss))
    {
        printf("300 420 moveto\n310 420 lineto\n");
        d=0;x=310;y=420;
        for(i=0;ss[i]!='\0';i++)
        {
            e=ss[i];
            if(e=='V')d=(d-1+400)%4;
            else if(e=='A')d=(d+1)%4;
            switch(d)
            {
            case 0:x+=10;break;
            case 1:y-=10;break;
            case 2:x-=10;break;
            case 3:y+=10;break;
            }
            printf("%d %d lineto\n",x,y);
        }
        printf("stroke\nshowpage\n");
    }
    return 0;
}
