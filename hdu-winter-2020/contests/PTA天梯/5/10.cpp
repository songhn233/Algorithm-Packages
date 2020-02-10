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
int n,s;
int head[maxn],num,ans;
vector<int> res;
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
		res.clear();
		res.push_back(u);
	}
	else if(d==ans) res.push_back(u);
	
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
		int x;read(x);
		if(x==-1) s=i;
		else add(x,i);
	}
	dfs(s,1);
	cout<<ans<<endl;
	sort(res.begin(),res.end());
	for(int i=0;i<res.size();i++)
	{
		if(i!=(int)res.size()-1) cout<<res[i]<<" ";
		else cout<<res[i]<<endl;
	}
	return 0;
}
