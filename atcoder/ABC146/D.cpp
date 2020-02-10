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
const int maxn=100050;
int n,in[maxn],res;
map<PII,int> co;
int head[maxn],num;
PII ans[maxn];
struct node{
	int v,nex;
}e[maxn<<1];
void add(int u,int v)
{
	e[++num].nex=head[u];
	e[num].v=v;
	head[u]=num;
}
void dfs(int u,int fa,int pre)
{
	int c=1;
	if(c==pre) c++;
	for(int i=head[u];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==fa) continue;
		co[make_pair(u,v)]=c;
		res=max(res,c);
		dfs(v,u,c);
		c++;
		if(c==pre) c++;
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		read(x),read(y);
		if(x>y) swap(x,y);
		ans[i]=make_pair(x,y);
		add(x,y),add(y,x);
	}
	dfs(1,0,0);
	cout<<res<<endl;
	for(int i=1;i<=n-1;i++) cout<<co[ans[i]]<<endl;
	return 0;
}

