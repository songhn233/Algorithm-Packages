// TODO this
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
const int maxn=750050;
int n,q;
int head[maxn],num,ans[maxn],f[maxn];
struct node{
    int v,nex;
}e[maxn<<1];
void add(int u,int v)
{
    e[++num].nex=head[u];
    e[num].v=v;
    head[u]=num;
}
void dfs(int u,int fa)
{
    for(int i=head[u];i;i=e[i].nex)
    {
        int v=e[i].v;
        if(v==fa) continue;
        f[v]=u;
        dfs(v,u);
    }
}
vector<int> t;
int main()
{
    cin>>n>>q;
    rep(i,1,n-1)
    {
        int x,y;rd(x),rd(y);
        add(x,y),add(y,x);
    }
    dfs(1,0);
    while(q--)
    {
        int x;rd(x);
        ans[x]++;
        t.clear();
        for(int i=head[x];i;i=e[i].nex)
        {
            int v=e[i].v;
            if(v==f[x]) continue;
            ans[v]++;
            t.push_back(v);
        }
        for(int j=0;j<t.size();j++)
        {
            int p=t[j];
            for(int i=head[p];i;i=e[i].nex)
            {
                int v=e[i].v;
                if(v==f[p]) continue;
                ans[v]++;
            }
        }
        if(f[x]) ans[f[x]]++;
        if(f[f[x]]) ans[f[f[x]]]++;
        if(f[x])
        {
            int p=f[x];
            for(int i=head[p];i;i=e[i].nex)
            {
                int v=e[i].v;
                if(v==f[p]||v==x) continue;
                ans[v]++;
            }
        }
        printf("%d\n",ans[x]);
    }
    return 0;
}