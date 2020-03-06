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
const int maxn=10010;
PII t[maxn],a[maxn];
int n,m;
int head[maxn],num;
int dfn[maxn],low[maxn],tot;
int sta[maxn],insta[maxn],s,c,co[maxn];
struct node{
	int v,nex;
}e[maxn];
void add(int u,int v)
{
	e[++num].nex=head[u];
	e[num].v=v;
	head[u]=num;
}
void tarjan(int u)
{
	dfn[u]=low[u]=++tot;
	sta[++s]=u;insta[u]=1;
	for(int i=head[u];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(insta[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		int t=-1;c++;
		do
		{
			t=sta[s--];
			insta[t]=0;
			co[t]=c;
		}
		while(t!=u);
	}
}
bool calc(int mid)
{
	memset(head,0,sizeof(head));num=0;
	memset(dfn,0,sizeof(dfn));memset(low,0,sizeof(low));
	memset(co,0,sizeof(co));
	memset(insta,0,sizeof(insta));
	tot=s=c=0;
	for(int i=1;i<=n;i++)
	{
		add(t[i].first,t[i].second+2*n);
		add(t[i].second,t[i].first+2*n);
	}
	for(int i=1;i<=mid;i++)
	{
		add(a[i].first+2*n,a[i].second);
		add(a[i].second+2*n,a[i].first);
	}
	for(int i=0;i<4*n;i++) if(!dfn[i]) tarjan(i);
	int flag=1;
	for(int i=0;i<2*n;i++)
	{
		if(co[i]==co[i+2*n]) 
		{
			flag=0;
			break;
		}
	}
	if(flag) return true;
	return false;
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		if(n==0&&m==0) break;
		for(int i=1;i<=n;i++)
		{
			int x,y;read(x),read(y);
			t[i]=make_pair(x,y);
		}
		for(int i=1;i<=m;i++)
		{
			int x,y;read(x),read(y);
			a[i]=make_pair(x,y);
		}
		int l=0,r=m;
		while(l<r)
		{
			int mid=l+r>>1;
			if(calc(mid)) l=mid;
			else r=mid-1;
		}
		cout<<l<<endl;
	}
	return 0;
}

