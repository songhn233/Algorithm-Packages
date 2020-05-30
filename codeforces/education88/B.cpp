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
const int maxn=1010;
int T;
int n,m,x,y;
char a[maxn][maxn],vis[maxn];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>x>>y;
        for(int i=1;i<=n;i++) cin>>(a[i]+1);
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++) vis[j]=0;
            for(int j=1;j<=m;j++)
            {
                if(vis[j]) continue;
                if(j<m&&a[i][j]=='.'&&a[i][j+1]=='.')
                {
                    if(y<2*x)
                    {
                        ans+=y;
                        vis[j]=vis[j+1]=1;
                        continue;
                    }
                    else
                    {
                        ans+=x;
                        vis[j]=1;
                        continue;
                    }
                }
                if(a[i][j]=='.')
                {
                    vis[j]=1;
                    ans+=x;
                    continue;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}