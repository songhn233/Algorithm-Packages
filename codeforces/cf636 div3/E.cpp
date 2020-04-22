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
int T;
int n,m,a,b,c;
vector<int> e[maxn];
int d1[maxn],d2[maxn],d3[maxn];
ll sum[maxn],p[maxn];
void bfs(int s,int d[])
{
    rep(i,1,n) d[i]=inf;
    d[s]=0;
    queue<int> q;
    while(!q.empty()) q.pop();
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=0;i<e[u].size();i++)
        {
            int v=e[u][i];
            if(d[v]==inf)
            {
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
}
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>a>>b>>c;
        rep(i,1,n) e[i].clear();
        sum[0]=0;
        rep(i,1,m) rd(p[i]);
        sort(p+1,p+m+1);
        rep(i,1,m) sum[i]=sum[i-1]+p[i];
        rep(i,1,m)
        {
            int x,y;rd(x),rd(y);
            e[x].push_back(y);
            e[y].push_back(x);
        }
        bfs(a,d1);
        bfs(b,d2);
        bfs(c,d3);
        ll ans=1e18;
        rep(i,1,n)
        {
            if(d2[i]+d1[i]+d3[i]>m) continue;
            ans=min(ans,sum[d2[i]]+sum[d2[i]+d1[i]+d3[i]]);
        }
        cout<<ans<<endl;
    }
    return 0;
}