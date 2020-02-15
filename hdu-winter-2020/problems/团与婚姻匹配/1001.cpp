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
const int maxn=55;
int n;
int a[maxn][maxn],f[maxn],temp[maxn][maxn],ans,tot;
bool dfs(int d,int num)
{
	if(num==0)
	{
		if(d>ans) 
		{
			ans=d;
			return true;
		}
		else return false;
	}
	for(int i=1;i<=num;i++)
	{
		if(d+num-i+1<=ans) return false;
		int v=temp[d][i];
		if(d+f[v]<=ans) return false;
		int cnt=0;
		for(int j=i+1;j<=num;j++)
		{
			int vv=temp[d][j];
			if(a[v][vv]) temp[d+1][++cnt]=vv;
		}
		if(dfs(d+1,cnt)) return true;
	}
	return false;
}
int main()
{
	while(~scanf("%d",&n))
	{
		if(n==0) break;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) read(a[i][j]);
		f[n]=ans=1;
		for(int i=n-1;i>=1;i--)
		{
			tot=0;
			for(int j=i+1;j<=n;j++)
			{
				if(a[i][j]) temp[1][++tot]=j;
			}
			dfs(1,tot);
			f[i]=ans;
		}
		cout<<ans<<endl;
	}
	return 0;
}
