#include<cstdio>   
#include<cstring>   
#include<queue>   
#include<cctype>   
using namespace std;  
  
struct S  
{  
    char maze[3][3];  
    int x,y;  
    int g,h,f;  
    S(){}  
    S(const S & ts)  
    {  
        memcpy(maze,ts.maze,sizeof(maze));  
        x=ts.x; y=ts.y;  
        g=ts.g; h=ts.h; f=ts.h;  
    }  
    friend bool operator <(const S&a, const S&b )  
    {  
        if(a.f==b.f)  
            return a.g<a.g;  
        return a.f>b.f;  
    }  
}s;  
  
const int fac[]={1,1,2,6,24,120,720,5040,40320};  
bool vis[363000];  
int pre[363000];  
char op[363000];  
  
//����չ�����ϣ   
int inv_hash(S ts)  
{  
    char str[10];  
    int ans=0;  
    for(int i=0;i<3;i++)  
        for(int j=0;j<3;j++)  
        {  
            str[i*3+j]=ts.maze[i][j];  
            int cnt=0;  
            for(int k=i*3+j-1;k>=0;k--)  
                if(str[k]>str[i*3+j]) cnt++;  
            ans+=fac[i*3+j]*cnt;  
        }  
    return ans;  
}  
//��hֵ,hֵ�����ʵ���ǵ�ǰ״̬�е�8������λ����Ŀ��λ�õ�ƫ��ֵ   
const int pos[][2]={{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};  
int Abs(int x)  {return x<0?-x:x;}  
  
int h(S ts)  
{  
    int val=0;  
    for(int i=0;i<3;i++)  
        for(int j=0;j<3;j++)  
        {  
            if(ts.maze[i][j]=='x')  
                continue;  
            int c=ts.maze[i][j]-'1';  
            val+=Abs(pos[c][0]-i)+Abs(pos[c][1]-j);  
        }  
        return val;  
}  
  
const int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};  
  
bool bfs()  
{  
    memset(vis,0,sizeof(vis));  
  
    priority_queue<S>qu;  
    qu.push(s);  
    while(!qu.empty())  
    {  
        S u=qu.top();   qu.pop();  
        int ihu=inv_hash(u);  
  
        for(int i=0;i<4;i++)  
        {  
            S v=u;  
            v.x+=dir[i][0];  
            v.y+=dir[i][1];  
            if(v.x<0 || v.x>=3 || v.y<0 || v.y>=3 ) continue;  
            {//�����д����൱���ƶ�X   
                v.maze[u.x][u.y]=u.maze[v.x][v.y];  
                v.maze[v.x][v.y]='x';  
            }  
            //���¼���g,h,fֵ   
            v.g+=1;  v.h=h(v); v.f=v.g+v.h;  
            int ihv=inv_hash(v);  
            if(vis[ihv]) continue;  
            vis[ihv]=1;  
            //��¼���ڵ�   
            pre[ihv]=ihu;  
            if(i==0) op[ihv]='d';  
            else if(i==1) op[ihv]='r';  
            else if(i==2) op[ihv]='u';  
            else if(i==3) op[ihv]='l';  
            if(ihv==0)  
                return true;  
            qu.push(v);  
        }  
    }  
    return false;  
}  
  
inline bool inv_check()  
{  
    char str[10];  
    int cnt=0;  
    for(int i=0;i<3;i++)  
        for(int j=0;j<3;j++)  
        {  
            str[i*3+j]=s.maze[i][j];  
            if(str[i*3+j]=='x')continue;  
            for(int k=i*3+j-1;k>=0;k--)  
            {  
                if(str[k]=='x') continue;  
                if(str[k]>str[i*3+j])  
                    cnt++;  
            }  
        }  
    return !(cnt&1);  
}  
  
char in[100];  
char stk[100];  
  
int main()  
{  
    while(gets(in))  
    {  
        for(int i=0,x=0,y=0;in[i];i++)  
        {  
            if((isdigit(in[i])) || in[i]=='x')  
            {  
                s.maze[x][y]=in[i];  
                if(in[i]=='x') {s.x=x;  s.y=y;}  
                y++;  
                if(y==3)  
                    y=0,x++;  
            }  
        }  
        if(!inv_check())  
        {  
            puts("unsolvable");  
            continue;  
        }  
        s.g=0;  s.h=h(s);  s.f=s.h;  
  
        //����������ݾ���Ŀ��״̬   
        int shash=inv_hash(s);  
        if(shash==0)  
        {  
            puts("");continue;  
        }  
  
        bfs();  
        //������   
        int top=-1,thash=0;  
        while(thash!=shash)//��ʼ�ܲ�����Ϊʲô�����ʱ���Ǵ�0��ʼ����ϣֵ��ô���ܻ���0��   
        {//��ĥ��һ��ŷ�Ӧ����������������״̬��ʱ�����ڲ���������ԣ����Թ�ϣֵһ����0��Ȼ�����˳�����   
            stk[++top]=op[thash];  
            thash=pre[thash];  
        }  
       /* for(int _i=top;_i>=0;_i--)  
            putchar(stk[_i]);  
        puts("");*/
		printf("%d\n",strlen(stk));
    }
	return 0;
}  