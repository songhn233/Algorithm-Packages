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
int n,w[maxn],size[maxn];
string s;
int head[maxn],num,fa[maxn];
struct node{
	int v,nex;
}e[maxn];
void add(int u,int v)
{
	e[++num].nex=head[u];
	e[num].v=v;
	head[u]=num;
}
int findx(int x){if(x!=fa[x]) fa[x]=findx(fa[x]); return fa[x];}
void merge(int x,int y)
{
	x=findx(x),y=findx(y);
	if(x==y) return ;
	fa[x]=y;
	size[y]+=size[x];
}
void dfs(int u,int fa)
{
	for(int i=head[u];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		if(w[u]==0&&w[v]==0) merge(v,u);
	}
}
ll calc(int u)
{
	ll res=0;
	vector<ll> temp;
	temp.clear();
	for(int i=head[u];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(w[v]) continue;
		temp.push_back(size[findx(v)]);
		res+=size[findx(v)];
	}
	for(int i=0;i<temp.size();i++)
	{
		for(int j=i+1;j<temp.size();j++)
			res+=temp[i]*temp[j];
	}
	return res;
}
int main()
{
	ll ans=0;
	cin>>n;
	cin>>s;
	for(int i=1;i<=n;i++) fa[i]=i,size[i]=1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='W') w[i+1]=0;
		else w[i+1]=1;
	}
	for(int i=1;i<n;i++)
	{
		int u,v;read(u),read(v);
		add(u,v),add(v,u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
	{
		if(w[i])
		{
			ans+=calc(i);
		}
	}
	cout<<ans<<endl;
	return 0;
}

