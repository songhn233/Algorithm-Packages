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
const int maxn=200500;
int n,root,ans,res;
map<int,int> mp;
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
void dfs(int u,int d)
{
	if(d>ans)
	{
		ans=d;
		res=u;
	}
	for(int i=head[u];i;i=e[i].nex)
	{
		int v=e[i].v;
		dfs(v,d+1);
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int k;read(k);
		for(int j=1;j<=k;j++)
		{
			int x;read(x);
			add(i,x);
			mp[x]=1;
		}
	}
	for(int i=1;i<=n;i++) 
		if(!mp[i]) 
		{
			root=i;
			break;
		}
	dfs(root,0);
	cout<<res<<endl;
	return 0;
}

