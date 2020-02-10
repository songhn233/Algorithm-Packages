#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define mst(a,b) memset((a),(b),sizeof(a))
#define PII pair<int,int>
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=250;
int n,m;
int d[maxn][maxn];
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(d,0x3f,sizeof(d));
        for(int i=0;i<n;i++) d[i][i]=0;
        for(int i=1;i<=m;i++)
        {
            int x,y;cin>>x>>y;
            d[x][y]=d[y][x]=1;
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                }
            }
        }
        int flag=1;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
                if(d[i][j]>7) flag=0;
        }
        if(flag) puts("Yes");
        else puts("No");
    }
    return 0;
}
