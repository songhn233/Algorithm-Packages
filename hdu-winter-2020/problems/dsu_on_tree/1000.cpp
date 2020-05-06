/* hdu4358 */
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
int T,n,k,q;
int w[maxn];
vector<int> e[maxn];
int siz[maxn],son[maxn],lim,ans[maxn];
map<int,int> mp,mmp;
int sum=0;
void dfs1(int u,int fa)
{
    siz[u]=1,son[u]=0;
    int maxx=0;
    for(int i=0;i<e[u].size();i++)
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
    mmp[mp[w[u]]]--;
    mp[w[u]]+=p;
    mmp[mp[w[u]]]++;
    for(int i=0;i<e[u].size();i++)
    {
        int v=e[u][i];
        if(v==fa||v==lim) continue;
        count(v,u,p);
    }
}
void dfs2(int u,int fa,int p)
{
    for(int i=0;i<e[u].size();i++)
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
    ans[u]=mmp[k];
    if(!p)
    {
        count(u,fa,-1);
        sum=0;
    }
}
int main()
{
    cin>>T;
    for(int tim=1;tim<=T;tim++)
    {
        rd(n),rd(k);
        rep(i,1,n) rd(w[i]);
        rep(i,1,n) e[i].clear();
        mp.clear();mmp.clear();
        rep(i,1,n-1)
        {
            int x,y;rd(x),rd(y);
            e[x].push_back(y);
            e[y].push_back(x);
        }
        mmp[0]=n;
        dfs1(1,0);
        dfs2(1,0,1);
        printf("Case #%d:\n",tim);
        rd(q);
        while(q--)
        {
            int x;rd(x);
            printf("%d\n",ans[x]);
        }
        if(tim!=T) printf("\n");
    }
    return 0;
}