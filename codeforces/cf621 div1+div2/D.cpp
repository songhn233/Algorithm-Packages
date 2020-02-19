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
const int maxn=400050;
int n,m,k,a[maxn],t[maxn],dis1[maxn],dis2[maxn],d[maxn];
int flag[maxn],fff[maxn];
int head[maxn],num;
PII E[maxn];
int fa[maxn];
int get(int x){if(x!=fa[x]) fa[x]=get(fa[x]); return fa[x];}
map<PII,bool> mp;
struct node{
	int v,nex;
}e[maxn];
void add(int u,int v)
{
	e[++num].nex=head[u];
	e[num].v=v;
	head[u]=num;
}
void merge(int x,int y)
{
	x=get(x),y=get(y);
	if(x==y) return ;
	fa[x]=y;
}
void bfs()
{
	queue<int> q;
	memset(dis1,0x3f,sizeof(dis1));
	while(!q.empty()) q.pop();
	q.push(1);
	dis1[1]=0;
	while(!q.empty())
	{
			int u=q.front();q.pop();
			for(int i=head[u];i;i=e[i].nex)
			{
				int v=e[i].v;
				merge(v,u);
				if(dis1[v]!=inf) continue;
				dis1[v]=dis1[u]+1;
				q.push(v);
			}
	}
}
void bfs2()
{
	queue<int> q;
	memset(dis2,0x3f,sizeof(dis2));
	while(!q.empty()) q.pop();
	q.push(n);
	dis2[n]=0;
	while(!q.empty())
	{
			int u=q.front();q.pop();
			for(int i=head[u];i;i=e[i].nex)
			{
				int v=e[i].v;
				if(dis2[v]!=inf) continue;
				dis2[v]=dis2[u]+1;
				q.push(v);
			}
	}
}
void bfs3()
{
	queue<int> q;
	memset(d,0x3f,sizeof(d));
	while(!q.empty()) q.pop();
	q.push(1);
	d[1]=0;
	while(!q.empty())
	{
			int u=q.front();q.pop();
			for(int i=head[u];i;i=e[i].nex)
			{
				int v=e[i].v;
				if(d[v]!=inf) continue;
				d[v]=d[u]+1;
				q.push(v);
			}
	}
}
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=k;i++)
	{
		read(t[i]);
		fff[t[i]]=1;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;read(x),read(y);
		add(x,y);add(y,x);
		E[i]=make_pair(x,y);
	}
	bfs();
	bfs2();
	int pan=dis1[n];
	for(int i=1;i<=n;i++)
	{
		if(dis1[i]+dis2[i]==pan)
		{
			flag[i]=1;
		}
	}
	memset(head,0,sizeof(head));num=0;
	for(int i=1;i<=m;i++)
	{
		int x=E[i].first,y=E[i].second;
		if(flag[x]&&flag[y]) add(x,y),add(y,x);
	}
	bfs3();
	int flag=0;
	for(int i=1;i<=m;i++)
	{
		int x=E[i].first,y=E[i].second;
		if(fff[x]&&fff[y])
		{
			flag=1;
			break;
		}
	}
	if(flag) cout<<pan<<endl;
	else
	{
		int maxx=0;
		for(int i=1;i<=k;i++)
		{
			for(int j=i+1;j<=k;j++)
			{
				if(get(t[i])==get(t[j]))
				{
					if(dis1[t[i]]>dis1[t[j]])
					{
						maxx=max(maxx,dis1[t[j]]+dis2[t[i]]+1);
					}
					else maxx=max(maxx,dis1[t[i]]+dis2[t[j]]+1);
				}
				else maxx=max(maxx,max(abs(dis1[t[i]]+dis2[t[j]]),abs(dis1[t[j]]+dis2[t[i]]))+1);
			}
		}
		cout<<maxx<<endl;
	}
	return 0;
}

