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
ll n,a[maxn],s[maxn];
vector<int> e[maxn];
vector<PII> p;
ll siz[maxn];
vector<ll> ans;
void dfs(int u,int fa)
{
    siz[u]=1;
    for(int i=0;i<e[u].size();i++)
    {
        int v=e[u][i];
        if(v==fa) continue;
        dfs(v,u);
        siz[u]+=siz[v];
    }
}
int main()
{
    cin>>n;
    rep(i,1,n-1)
    {
        int x,y;rd(x),rd(y);
        if(x>y) swap(x,y);
        e[x].push_back(y);
        p.push_back(make_pair(x,y));
    }
    dfs(1,0);
    for(int i=0;i<n-1;i++)
    {
        int x=p[i].first,y=p[i].second;
        ll t1=siz[y],t2=n-siz[y];
        ans.push_back(t1*t2);
    }
    sort(ans.begin(),ans.end());
    ll res=0;
    for(int i=0;i<ans.size();i++)
    {
        ll val=ans[i];
        res+=val*(n-i-1);
    }
    cout<<res<<endl;
    return 0;
}