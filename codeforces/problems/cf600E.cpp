//https://codeforces.com/contest/600/problem/E
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
const int maxn=200050;
int n,c[maxn],siz[maxn],son[maxn],mp[maxn];
vector<int> e[maxn];
ll sum,maxx,lim,ans[maxn];
void dfs1(int u,int fa)
{
    siz[u]=1,son[u]=0;
    int maxx=0;
    rep(i,0,(int)e[u].size()-1)
    {
        int v=e[u][i];
        if(v==fa) continue;
        dfs1(v,u);
        siz[u]+=siz[v];
        if(siz[v]>maxx)
        {
            maxx=siz[v];
            son[u]=v;
        }
    }
}
void count(int u,int fa,int p)
{
    mp[c[u]]+=p;
    if(mp[c[u]]>maxx)
    {
        maxx=mp[c[u]];
        sum=c[u];
    }
    else if(mp[c[u]]==maxx) sum+=c[u];

    rep(i,0,(int)e[u].size()-1)
    {
        int v=e[u][i];
        if(v==fa||v==lim) continue;
        count(v,u,p);
    }
}
void dfs2(int u,int fa,int flag)
{
    rep(i,0,(int)e[u].size()-1)
    {
        int v=e[u][i];
        if(v==fa||v==son[u]) continue;
        dfs2(v,u,0);
    }
    if(son[u])
    {
        dfs2(son[u],u,1);
        lim=son[u];
    }
    count(u,fa,1);
    lim=0;
    ans[u]=sum;
    if(!flag)
    {
        count(u,fa,-1);
        sum=0;
        maxx=0;
    }
}
int main()
{
    cin>>n;
    rep(i,1,n) rd(c[i]);
    rep(i,1,n-1)
    {
        int x,y;rd(x),rd(y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs1(1,0);
    dfs2(1,0,1);
    rep(i,1,n) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}