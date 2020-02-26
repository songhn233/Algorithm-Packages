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
const int maxn=20000;
int n,m,tot,vis[maxn],sta[maxn];
vector<int> e[maxn]; 
void add(int x,int y){e[x].push_back(y);}
bool dfs(int x)
{
	if(vis[x^1]) return false;
	if(vis[x]) return true;
	vis[x]=1;
	sta[++tot]=x;
	for(int i=0;i<e[x].size();i++)
	{
		int v=e[x][i];
		if(!dfs(v)) return false;
	}
	return true;
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		memset(vis,0,sizeof(vis));
		for(int i=0;i<2*n;i++) e[i].clear();
		for(int i=1;i<=m;i++)
		{
			int x,y;read(x),read(y);
			x--,y--;
			add(x,y^1);
			add(y,x^1);
		}
		int flag=1;
		for(int i=0;i<2*n;i+=2)
		{
			if(vis[i]||vis[i^1]) continue;
			tot=0;
			if(!dfs(i))
			{
				while(tot) vis[sta[tot--]]=0;
				if(!dfs(i^1))
				{
					puts("NIE");
					flag=0;
					break;
				}
			}
		}
		if(flag)
		{
			for(int i=0;i<2*n;i++) if(vis[i]) cout<<i+1<<endl;
		}
	}
	return 0;
}

