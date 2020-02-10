#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100050;
int f[maxn][11],a[maxn][11],n,m;
inline int read()
{
    int x=0,t=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*t;
}
int main()
{
    while(cin>>n)
    {
        if(n==0) break;
        m=0;
        memset(f,0,sizeof(f));
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
        {
            int x,y;x=read(),y=read();
            a[y][x]+=1;
            m=max(m,y);
        }
        for(int i=0;i<=10;i++) f[m][i]=a[m][i];
        for(int i=m-1;i>=0;i--)
        {
            for(int j=0;j<=10;j++)
            {
                if(j==0) f[i][0]=max(f[i+1][0],f[i+1][1])+a[i][0];
                else if(j==10) f[i][10]=max(f[i+1][9],f[i+1][10])+a[i][10];
                else f[i][j]=max(f[i+1][j],max(f[i+1][j-1],f[i+1][j+1]))+a[i][j];
            }
        }
        printf("%d\n",f[0][5]);
    }
    return 0;
}
