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
const int maxn=20050;
const int inf=0x3f3f3f3f;
int n,m,dis[maxn],vis[maxn],ed,cnt;
int head[maxn],num;
struct node{
    int v,w,nex;
}e[maxn];
void add(int u,int v,int w)
{
    e[++num].nex=head[u];
    e[num].v=v;e[num].w=w;
    head[u]=num;
}
void dij()
{
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    priority_queue<PII,vector<PII>,greater<PII> > q;
    dis[0]=0;
    q.push(make_pair(0,0));
    while(!q.empty())
    {
        int u=q.top().second;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i;i=e[i].nex)
        {
            int v=e[i].v;
            if(dis[v]>dis[u]+e[i].w)
            {
                dis[v]=dis[u]+e[i].w;
                q.push(make_pair(dis[v],v));
            }
        }
    }
    if(dis[ed]==inf) puts("-1");
    else cout<<dis[ed]<<endl;
}
int main()
{
    while(~scanf("%d%d%d",&n,&m,&ed))
    {
    	if(n==0&&m==0) break;
    	memset(head,0,sizeof(head));num=0;
    	for(int i=1;i<=m;i++)
    	{
    		int u,v,w;
    		read(u),read(v),read(w);
    		add(u,v,w);
		}
		cin>>cnt;
		for(int i=1;i<=cnt;i++)
		{
			int x;read(x);
			add(0,x,0);
		}
		dij();
	}
    return 0;
}
