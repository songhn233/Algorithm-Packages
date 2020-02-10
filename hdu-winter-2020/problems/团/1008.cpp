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
const int maxn=150;
int T,n,m,a[maxn][maxn],f[maxn],p;
int temp[maxn][maxn],ans,tot,vis[maxn];
vector<int> res;
bool dfs(int d,int num)
{
	if(num==0)
	{
		if(d>ans) 
		{
			ans=d;
			res.clear();
			res.push_back(p);
			for(int i=1;i<=n;i++)
			{
				if(vis[i]) res.push_back(i);
			}
			return true;
		}
		else return false;
	}
	for(int i=1;i<=num;i++)
	{
		if(d+num-i+1<=ans) return false;
		int v=temp[d][i];
		if(d+f[v]<=ans) return false;
		vis[v]=1;
		int cnt=0;
		for(int j=i+1;j<=num;j++)
		{
			int vv=temp[d][j];
			if(a[v][vv]) temp[d+1][++cnt]=vv;
		}
		if(dfs(d+1,cnt)) return true;
		vis[v]=0;
	}
	return false;
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		memset(f,0,sizeof(f));
		
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]=1;
		for(int i=1;i<=m;i++)
		{
			int x,y;read(x),read(y);
			a[x][y]=a[y][x]=0;
		}
		f[n]=ans=1;
		for(int i=n-1;i>=1;i--)
		{
			tot=0;
			for(int j=i+1;j<=n;j++)
			{
				if(a[i][j]) temp[1][++tot]=j;
			}
			memset(vis,0,sizeof(vis));
			p=i;
			dfs(1,tot);
			f[i]=ans;
		}
		cout<<ans<<endl;
		for(int i=0;i<res.size();i++)
		{
			if(i!=(int)res.size()-1) cout<<res[i]<<" ";
			else cout<<res[i]<<endl;
		}
	}
	return 0;
}

