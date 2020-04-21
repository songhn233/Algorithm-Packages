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
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
template<class T>inline void rd(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=1050;
int T;
int n,m,k;
int vis[maxn][maxn];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>k;
        rep(i,1,n) rep(j,1,m) vis[i][j]=0;
        rep(i,1,k)
        {
            int x,y;
            rd(x),rd(y);
            vis[x][y]=1;
        }
        int flag=0;
        int t1=(n+1)/2,t2=m/2;
        int ans=inf;
        int a1,a2;
        rep(i,1,n)
        {
            rep(j,1,m-1)
            {
                if(vis[i][j]||vis[i][j+1]) continue;
                if(abs(i-t1)+abs(j-t2)<ans)
                {
                    ans=abs(i-t1)+abs(j-t2);
                    a1=i,a2=j;
                }
                else if(abs(i-t1)+abs(j-t2)==ans)
                {
                    if(i<a1) a1=i,a2=j;
                    else if(i==a1&&j<a2) a1=i,a2=j;
                }
            }
        }
        if(ans==inf) puts("-1");
        else
        {
            printf("(%d,%d) (%d,%d)\n",a1,a2,a1,a2+1);
        }
    }
    return 0;
}