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
const int maxn=50050;
int n,m;
int head[maxn],num,st,ed;
int vis[maxn],dis[maxn],pre[maxn],cnt[maxn];
int ans1,ans2;
vector<int> res1,res2;
struct node{
	int v,w,t,nex;
}e[maxn];
void add(int u,int v,int w,int t)
{
	e[++num].nex=head[u];
	e[num].v=v;e[num].w=w;e[num].t=t;
	head[u]=num;
}
void dij_t(int s)
{
	memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    memset(pre,-1,sizeof(pre));
    memset(cnt,0,sizeof(cnt));
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
            if(dis[u]+e[i].t<dis[v])
            {
                dis[v]=dis[u]+e[i].t;
                cnt[v]=cnt[u]+e[i].w;
                q.push(make_pair(dis[v],v));
                pre[v]=u;
            }
            else if(dis[u]+e[i].t==dis[v])
            {
            	if(cnt[v]>cnt[u]+e[i].w)
            	{
            		cnt[v]=cnt[u]+e[i].w;
                	q.push(make_pair(dis[v],v));
                	pre[v]=u;
				}
			}
        }
    }
    int temp=ed;
    while(temp!=-1) 
    {
    	res1.push_back(temp);
    	temp=pre[temp];
	}
	ans1=dis[ed];
}
void dij(int s)
{
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    memset(pre,-1,sizeof(pre));
    memset(cnt,0,sizeof(cnt));
    priority_queue<PII,vector<PII>,greater<PII> > q;
    q.push(make_pair(0,s));
    dis[s]=0;cnt[s]=1;
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
                cnt[v]=cnt[u]+1;
                q.push(make_pair(dis[v],v));
                pre[v]=u;
            }
            else if(dis[u]+e[i].w==dis[v])
            {
            	if(cnt[v]>cnt[u]+1)
            	{
            		cnt[v]=cnt[u]+1;
                	q.push(make_pair(dis[v],v));
                	pre[v]=u;
				}
			}
        }
    }
    int temp=ed;
    while(temp!=-1) 
    {
    	res2.push_back(temp);
    	temp=pre[temp];
	}
	ans2=dis[ed];
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b,c,d,e;
		read(a),read(b),read(c),read(d),read(e);
		if(c)
		{
			add(a,b,d,e);
		}
		else
		{
			add(a,b,d,e);
			add(b,a,d,e);
		}
	}
	cin>>st>>ed;
	dij_t(st);
	dij(st);
	if(res1==res2) 
	{
		cout<<"Time = "<<ans1<<"; Distance = "<<ans2<<": ";
		for(int i=(int)res1.size()-1;i>=0;i--)
		{
			if(i==(int)res1.size()-1) cout<<res1[i];
			else cout<<" => "<<res1[i]; 
		}
		cout<<endl;
	}
	else
	{
		cout<<"Time = "<<ans1<<": ";
		for(int i=(int)res1.size()-1;i>=0;i--)
		{
			if(i==(int)res1.size()-1) cout<<res1[i];
			else cout<<" => "<<res1[i]; 
		}
		cout<<endl;
		cout<<"Distance = "<<ans2<<": ";
		for(int i=(int)res2.size()-1;i>=0;i--)
		{
			if(i==(int)res2.size()-1) cout<<res2[i];
			else cout<<" => "<<res2[i]; 
		}
		cout<<endl;
	}
	return 0;
}

