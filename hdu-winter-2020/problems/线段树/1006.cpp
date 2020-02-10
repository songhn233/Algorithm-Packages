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
#define ls id<<1
#define rs id<<1|1
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=100050;
int T,n,m;
int head[maxn],num;
int dfn[maxn],size[maxn],tot;
struct node{
	int v,nex;
}e[maxn];
void add(int u,int v)
{
	e[++num].nex=head[u];
	e[num].v=v;
	head[u]=num;
}
struct edge{
	int id,b,c;
	bool operator<(const edge&t) const{
		return c>t.c;
	}
}a[maxn];
void dfs(int u,int fa)
{
	size[u]=1;
	dfn[u]=++tot;
	for(int i=head[u];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		size[u]+=size[v];
	}
}
vector<int> ans;
int tans[maxn];
struct tree{
	int id,l,r;
	int maxx;
}t[maxn<<2];
void build(int id,int l,int r)
{
	t[id].l=l,t[id].r=r,t[id].maxx=-1;
	if(l==r)
	{
		t[l].maxx=-1;
		return ;
	}
	int mid=l+r>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[id].maxx=max(t[ls].maxx,t[rs].maxx);
}
void change(int id,int x,int p)
{
	if(t[id].l==t[id].r)
	{
		t[id].maxx=p;
		return ;
	}
	int mid=t[id].l+t[id].r>>1;
	if(x<=mid) change(ls,x,p);
	else change(rs,x,p);
	t[id].maxx=max(t[ls].maxx,t[rs].maxx);
}
int query(int id,int l,int r)
{
	if(t[id].l>=l&&t[id].r<=r)
	{
		return t[id].maxx;
	}
	int mid=t[id].l+t[id].r>>1;
	int res=-1;
	if(l<=mid) res=max(res,query(ls,l,r));
	if(r>mid) res=max(res,query(rs,l,r));
	return res;
}
map<int,int> mp;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		memset(head,0,sizeof(head));num=0;
		memset(size,0,sizeof(size));memset(tans,0,sizeof(tans));
		memset(dfn,0,sizeof(dfn));tot=0;
		mp.clear();ans.clear();
		a[0].id=0,a[0].b=-1,a[0].c=-1;
		for(int i=1;i<n;i++)
		{
			int x;
			read(x),read(a[i].b),read(a[i].c);
			add(x,i);
			mp[a[i].b]=i;
			a[i].id=i;
		}
		sort(a,a+n);
		dfs(0,-1);
		build(1,1,n);
		while(m--) 
		{
			int x;read(x);
			ans.push_back(x);
		}
		int pos=0,temp=0;
		while(pos<n)
		{
			while(temp<pos&&a[temp].c>a[pos].c)
			{
				change(1,dfn[a[temp].id],a[temp].b);
				temp++;
			}
			int tt=query(1,dfn[a[pos].id],dfn[a[pos].id]+size[a[pos].id]-1);
			if(tt==-1) tans[a[pos].id]=-1;
			else tans[a[pos].id]=mp[tt];
			pos++;
		}
		for(int i=0;i<ans.size();i++) cout<<tans[ans[i]]<<endl;
	}
	return 0;
}

