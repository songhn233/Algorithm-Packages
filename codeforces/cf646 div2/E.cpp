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
const int maxn=400050;
int n,t1,t2,p1,p2,num,head[maxn];
int a[maxn],b[maxn],c[maxn],s1[maxn],s2[maxn];
struct node{
    int v,nex;
}e[maxn];
void add(int u,int v)
{
    e[++num].nex=head[u];
    e[num].v=v;
    head[u]=num;
}
ll ans=0;
void dfs(int u,int fa,int t)
{
    t=min(t,a[u]);
    s1[u]=s2[u]=0;
    for(int i=head[u];i;i=e[i].nex)
    {
        int v=e[i].v;
        if(v==fa) continue;
        dfs(v,u,t);
        s1[u]+=s1[v];
        s2[u]+=s2[v];
    }
    if(b[u]==1&&c[u]==0) s1[u]++;
    if(b[u]==0&&c[u]==1) s2[u]++;
    ans+=2ll*min(s1[u],s2[u])*t;
    s1[u]-=min(s1[u],s2[u]);
    s2[u]-=min(s1[u],s2[u]);
}
signed main()
{
    cin>>n;
    rep(i,1,n) 
    {
        rd(a[i]),rd(b[i]),rd(c[i]);
        if(b[i]==1&&c[i]==0) t1++;
        if(b[i]==0&&c[i]==1) t2++;
    }
    rep(i,1,n-1)
    {
        int u,v;rd(u),rd(v);
        add(u,v);
        add(v,u);
    }
    if(t1!=t2) puts("-1");
    else
    {
        ans=0;
        dfs(1,0,inf);
        cout<<ans<<endl;
    }
    return 0;
}