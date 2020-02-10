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
const int maxn=10050;
int n,m,c,co[maxn],q;
int head[maxn],num,vis[maxn];
struct node{
	int v,nex;
}e[maxn];
void add(int u,int v)
{
	e[++num].nex=head[u];
	e[num].v=v;
	head[u]=num;
}
int main()
{
	cin>>n>>m>>c;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		read(u),read(v);
		add(u,v),add(v,u);
	}
	cin>>q;
	while(q--)
	{
		memset(vis,0,sizeof(vis));
		map<int,int> mp;
		mp.clear();
		for(int i=1;i<=n;i++) read(co[i]),mp[co[i]]=1;
		int tt=mp.size();
		if(tt!=c) puts("No");
		else
		{
			int pan=1;
		for(int u=1;u<=n;u++)
		{
			for(int i=head[u];i;i=e[i].nex)
			{
				int v=e[i].v;
				if(co[v]==co[u]) pan=0;
			}
		}
		if(pan) puts("Yes");
		else puts("No");
		}
		
	}
	return 0;
}

