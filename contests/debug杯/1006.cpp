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
const int maxn=100050;
ll T,n;
vector<int> e[maxn];
ll p[maxn],c[maxn],t[maxn];
void dfs(int u,int fa)
{
    for(int i=0;i<e[u].size();i++)
    {
        int v=e[u][i];
        if(v==fa) continue;
        dfs(v,u);
        if(t[v]<0) t[u]+=t[v];
    }
}
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        rep(i,1,n) e[i].clear();
        rep(i,1,n-1)
        {
            int x,y;rd(x),rd(y);
            e[x].push_back(y);
            e[y].push_back(x);
        }
        rep(i,1,n)
        {
            rd(p[i]),rd(c[i]);
            t[i]=c[i]-p[i];
        }
        dfs(1,0);
        if(t[1]>=0) puts("YES");
        else puts("NO");
    }
    return 0;
}