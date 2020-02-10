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
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=20050;
int n,cnt;
map<string,int> mp;
string S,T;
int s,t;
int dis[maxn],vis[maxn];
int head[maxn],num;
struct edge{
    string u,v;
    int w;
}a[maxn];
struct node{
    int v,w,nex;
}e[maxn];
void add(int u,int v,int w){
    e[++num].nex=head[u];
    e[num].w=w;e[num].v=v;
    head[u]=num;
}
void dij()
{
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    priority_queue<PII,vector<PII>,greater<PII> > q;
    q.push(make_pair(0,s));
    dis[s]=0;
    while(!q.empty())
    {
        int u=q.top().second;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i;i=e[i].nex)
        {
            int v=e[i].v;
            if(dis[u]+e[i].w<dis[v])
            {
                dis[v]=dis[u]+e[i].w;
                q.push(make_pair(dis[v],v));
            }
        }
    }
    if(dis[t]==inf) puts("-1");
    else cout<<dis[t]<<endl;
}
int main()
{
    while(cin>>n)
    {
    if(n==-1) break;
    cin>>S>>T;
    cnt=num=0;
    mp.clear();
    memset(head,0,sizeof(head));
    mp[S]=++cnt;mp[T]=++cnt;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].u>>a[i].v>>a[i].w;
        if(!mp[a[i].u]) mp[a[i].u]=++cnt;
        if(!mp[a[i].v]) mp[a[i].v]=++cnt;
    }
    for(int i=1;i<=n;i++)
    {
        add(mp[a[i].u],mp[a[i].v],a[i].w);
        add(mp[a[i].v],mp[a[i].u],a[i].w);
    }
    s=mp[S],t=mp[T];
    dij();
    }
    return 0;
}
