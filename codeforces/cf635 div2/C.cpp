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
int n,k;
vector<int> e[maxn];
struct node{
    ll siz,d;
    bool operator<(const node &t) const{
        return ((d-(siz-1))>(t.d-(t.siz-1)));
    }
}a[maxn];
void dfs(int u,int f)
{
    a[u].siz=1;
    for(int i=0;i<e[u].size();i++)
    {
        int v=e[u][i];
        if(v==f) continue;
        a[v].d=a[u].d+1;
        dfs(v,u);
        a[u].siz+=a[v].siz;
    }
}
int main()
{
    cin>>n>>k;
    rep(i,1,n-1)
    {
        int x,y;rd(x),rd(y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    a[1].d=0;
    dfs(1,0);
    sort(a+1,a+n+1);
    ll ans=0;
    rep(i,1,k) ans+=a[i].d-(a[i].siz-1);
    cout<<ans<<endl;
    return 0;
}