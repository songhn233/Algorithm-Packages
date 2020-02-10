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
ll n,p[maxn],vis[maxn];
double z,r;
double val[maxn];
double ans;
int head[maxn],num;
struct node{
	int v,nex;
}e[maxn];
void add(int u,int v)
{
	e[++num].nex=head[u];
	e[num].v=v;
	head[u]=num;
}
void dfs(int u,int fa)
{
	if(fa!=-1)
	{
		if(!vis[u]) val[u]=val[fa]*r;
		else
		{
			val[u]=val[fa]*r*p[u];
			ans+=val[u];
		}
	}
	for(int i=head[u];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
	}
}
int main()
{
	cin>>n>>z>>r;
	for(int i=0;i<n;i++)
	{
		int k;read(k);
		if(k==0)
		{
			int x;read(x);
			p[i]=x;
			vis[i]=1;
		}
		else
		{
			for(int j=1;j<=k;j++)
			{
				int x;read(x);
				add(i,x);
			}
		}
	}
	val[0]=z;
	r*=0.01;
	r=1.0-r;
	dfs(0,-1);
	ll res=(ll)ans;
	if(n==1&&vis[0]) cout<<(ll)(z*p[0])<<endl;
	else cout<<res<<endl;
	return 0;
}
