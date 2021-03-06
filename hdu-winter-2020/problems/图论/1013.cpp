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
const int maxn=200050;
int n,m,head[maxn],num;
int dis[maxn],vis[maxn],co[maxn];
int s,t;
struct node{
    int v,w,nex,c;
}e[maxn];
void add(int u,int v,int w,int c){
    e[++num].nex=head[u];
    e[num].w=w;e[num].v=v;e[num].c=c;
    head[u]=num;
}
void dij()
{
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    memset(co,0,sizeof(co));
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
                co[v]=co[u]+e[i].c;
            }
            else if(dis[u]+e[i].w==dis[v]&&co[u]+e[i].c<co[v]) co[v]=co[u]+e[i].c;
        }
    }
    cout<<dis[t]<<" "<<co[t]<<endl;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0) break;
        num=0;
        memset(head,0,sizeof(head));
        for(int i=1;i<=m;i++)
        {
            int x,y,z,c;
            read(x),read(y),read(z);read(c);
            add(x,y,z,c),add(y,x,z,c);
        }
        cin>>s>>t;
        dij();
    }
    return 0;
}
