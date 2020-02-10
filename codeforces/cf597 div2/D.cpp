#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define PLL pair<ll,ll>
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=2010;
const int maxm=4003000;
ll n,m,T;
ll fa[maxn],w[maxn];
ll get(int x){if(x!=fa[x])fa[x]=get(fa[x]); return fa[x];}
struct node{
	ll x,y,k;
}p[maxn];
ll calc(ll t1,ll t2)
{
	ll x1=p[t1].x,x2=p[t2].x,y1=p[t1].y,y2=p[t2].y;
	return (abs(x1-x2)+abs(y1-y2))*(p[t1].k+p[t2].k);
}
map<pair<int,int>,bool> mp;

struct edge{
	ll u,v,w;
	bool operator<(const edge&t) const{
		return w<t.w;
	}
}e[maxm];
void add(ll u,ll v,ll w){e[++m]={u,v,w};}
ll ans1,ans2;
vector<ll> path;
vector<PLL> con;
ll kruskal()
{
	for(int i=0;i<=n;i++) fa[i]=i;
	sort(e+1,e+m+1);
	ll ans=0;
	for(int i=1;i<=m;i++)
	{
		ll x=e[i].u,y=e[i].v;
		x=get(x),y=get(y);
		if(x==y) continue;
		if(e[i].u==0) 
		{
			ans1++;
			path.push_back(e[i].v);
		}
		else 
		{
			ans2++;
			con.push_back(make_pair(e[i].u,e[i].v));
		}
		fa[x]=y;
		ans+=e[i].w;
	}
	return ans;
}
int main()
{
	while(cin>>n)
	{
		m=ans1=ans2=0;path.clear();con.clear();
		for(int i=1;i<=n;i++)
		{
			int x,y;cin>>x>>y;
			p[i]={x,y,0};
		}
		for(int i=1;i<=n;i++) cin>>w[i];
		for(int i=1;i<=n;i++) cin>>p[i].k;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				add(i,j,calc(i,j));
			}

		for(int i=1;i<=n;i++) add(0,i,w[i]);
		cout<<kruskal()<<endl;
		cout<<ans1<<endl;
		for(int i=0;i<path.size();i++) cout<<path[i]<<" ";
		puts("");
		cout<<ans2<<endl;
		for(int i=0;i<con.size();i++) cout<<con[i].first<<" "<<con[i].second<<endl;
	}
	return 0;
}
