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
const int maxn=1000050;
int n;
int head[maxn],num,d[maxn];
struct node{
	int v,nex;
}e[maxn];
void add(int u,int v)
{
	e[++num].nex=head[u];
	e[num].v=v;
	head[u]=num;
}
void dfs(int u)
{
	for(int i=head[u];i;i=e[i].nex)
	{
		int v=e[i].v;
		d[v]=d[u]+1;
		dfs(v);
	}
}
int main()
{
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		int x;read(x);
		add(x,i);
	}
	dfs(1);
	int t1=0,t2=0;
	for(int i=1;i<=n;i++) 
	{
		if(d[i]%2) t1++;
		else t2++;
	}
	cout<<t1*(t1-1)+t2*(t2-1)<<endl;
	return 0;
}

