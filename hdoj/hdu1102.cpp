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
const int maxn=150;
const int maxm=20005;
int T,n,m,num;
struct node{
	int u,v,w;
	bool operator<(const node&t) const{
		return w<t.w;
	}
}e[maxm];
struct edge{
	int x,y;
}a[maxn];
int fa[maxn],ans;
int get(int x){if(x!=fa[x])fa[x]=get(fa[x]); return fa[x];}
void kruskal()
{
	sort(e+1,e+num+1);
	for(int i=1;i<=num;i++)
	{
		int x=e[i].u,y=e[i].v;
		x=get(x),y=get(y);
		if(x==y) continue;
		fa[x]=y;
		ans+=e[i].w;
	}
	cout<<ans<<endl;
}
int main()
{
	while(~scanf("%d",&n))
	{
		num=ans=0;
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int t;read(t);
				e[++num]={i,j,t};
			}
		}
		cin>>m;
		while(m--)
		{
			int x,y;
			read(x),read(y);
			x=get(x),y=get(y);
			if(x==y) continue;
			fa[x]=y;
		}
		kruskal();
	}
	return 0;
}

