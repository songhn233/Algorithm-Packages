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
vector<int> e[maxn];
int n,in[maxn],root,dis[maxn],f[maxn];
vector<int> p;
map<int,int> vis;
void dfs(int u,int fa)
{
    f[u]=fa;
    for(int i=0;i<e[u].size();i++)
    {
        int v=e[u][i];
        if(v==fa) continue;
        dis[v]=dis[u]+1;
        dfs(v,u);
    }

}
int main()
{
    cin>>n;
    rep(i,1,n) 
    {
        e[i].clear();
        in[i]=0;
    }
    p.clear();
    rep(i,1,n-1)
    {
        int x,y;rd(x),rd(y);
        e[x].push_back(y);
        e[y].push_back(x);
        in[x]++,in[y]++;
    }
    rep(i,1,n) 
    {
        if(in[i]>1){root=i;break;}
    }
    rep(i,1,n)
    {
        if(in[i]==1) p.push_back(i);
    }
    dis[root]=0;f[root]=0;
    dfs(root,0);
    int f1,f2;f1=f2=0;
    for(int i=0;i<p.size();i++)
    {
        if(dis[p[i]]%2==1) f1=1;
        else f2=1;
    }
    if(f1==1&&f2==1) cout<<"3 ";
    else cout<<"1 ";
    int ans=n-1;vis.clear();
    for(int i=0;i<p.size();i++)
    {
        vis[f[p[i]]]++;
    }
    for(auto x:vis)
    {
        ans-=(x.second-1);
    }
    cout<<ans<<endl;
    return 0;
}