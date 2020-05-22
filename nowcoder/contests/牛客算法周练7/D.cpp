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
const int maxn=600005;
int head[maxn],num=1;
struct node{
    int v,nex;
}e[maxn];
void add(int u,int v)
{
    e[++num].nex=head[u];
    e[num].v=v;
    head[u]=num;
}
int n,m;
int dfn[maxn],low[maxn],sta[maxn],s,co[maxn],cc[maxn];
int tot,cnt,b[maxn];
set<int> mp[maxn];
void tarjan(int u,int fa)
{
    dfn[u]=low[u]=++tot;
    sta[++s]=u;
    for(int i=head[u];i;i=e[i].nex)
    {
        int v=e[i].v;
        if(!dfn[v])
        {
            tarjan(v,i);
            low[u]=min(low[u],low[v]);
        }
        else if(i!=(fa^1)) low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        cnt++;
        int temp=0;
        do
        {
            temp=sta[s--];
            co[temp]=cnt;
        } while (temp!=u);
        
    }
}
int main() {
    cin>>n>>m;
    rep(i,1,m)
    {
        int x,y;
        rd(x),rd(y);
        add(x,y);add(y,x);
    }
    tarjan(1,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=head[i];j;j=e[j].nex)
        {
            int v=e[j].v;
            if(co[v]==co[i]) 
            {
                cc[co[i]]++;
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=cnt;i++) ans+=cc[i]/2;
    cout<<ans<<endl;
    return 0;
}