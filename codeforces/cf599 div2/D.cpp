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
int n,m;
map<int,int> e[maxn];
set<int> s;
void dfs(int u)
{
	vector<int> res;
	res.clear();
	for(auto v:s)
	{
		if(e[u][v]==1) continue;
		res.push_back(v);
	}
	for(auto v:res) s.erase(v);
	for(auto v:res) dfs(v);
}
int main()
{
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int x,y;read(x),read(y);
		e[x][y]=e[y][x]=1;
	}
	for(int i=1;i<=n;i++) s.insert(i);
	while(!s.empty())
	{
		int u=*s.begin();s.erase(u);
		dfs(u);
		ans++;
	}
	cout<<ans-1<<endl;
	return 0;
}

