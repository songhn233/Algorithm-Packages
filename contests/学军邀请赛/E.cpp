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
int n;
vector<int> e[maxn];
int st,ed,a[maxn];
int dis[maxn],d1[maxn],d2[maxn];
int bfs(int s)
{
    queue<int> q;
    while(!q.empty()) q.pop();
    q.push(s);
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        rep(i,0,(int)e[u].size()-1)
        {
            int v=e[u][i];
            if(dis[v]==inf) 
            {
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
    int res=0,maxx=0;
    rep(i,1,n)
    {
        if(dis[i]>maxx)
        {
            maxx=dis[i];
            res=i;
        }
    }
    return res;
}
void bfs_1(int s)
{
    queue<int> q;
    while(!q.empty()) q.pop();
    q.push(s);
    mst(d1,0x3f);
    d1[s]=0;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        rep(i,0,(int)e[u].size()-1)
        {
            int v=e[u][i];
            if(d1[v]==inf)
            {
                d1[v]=d1[u]+1;
                q.push(v);
            }
        }
    }
}
void bfs_2(int s)
{
    queue<int> q;
    while(!q.empty()) q.pop();
    q.push(s);
    mst(d2,0x3f);
    d2[s]=0;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        rep(i,0,(int)e[u].size()-1)
        {
            int v=e[u][i];
            if(d2[v]==inf)
            {
                d2[v]=d2[u]+1;
                q.push(v);
            }
        }
    }
}
int main()
{
    cin>>n;
    rep(i,1,n) rd(a[i]);
    rep(i,1,n-1)
    {
        int x,y;rd(x),rd(y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    int st=bfs(1);
    int ed=bfs(st);
    bfs_1(st);
    bfs_2(ed);
    int ans=0;
    rep(i,1,n)
    {
        ans=max(ans,a[i]*max(d1[i],d2[i]));
    }
    cout<<ans<<endl;
    return 0;
}