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
const int maxn=250;
int n,m,a[maxn][maxn],ans;
int r[maxn][maxn],p[maxn][maxn],none[maxn][maxn];
void bk(int dep,int rn,int pn,int nn)
{
	if(!pn&&!nn) ans++;
	if(ans>1000) return ;
	int u=p[dep][1];
	for(int i=1;i<=pn;i++)
	{
		int v=p[dep][i],ppn=0,nnn=0;
		if(a[u][v]) continue;
		for(int j=1;j<=rn;j++) r[dep+1][j]=r[dep][j];
		r[dep+1][rn+1]=v;
		for(int j=1;j<=pn;j++) if(a[v][p[dep][j]]) p[dep+1][++ppn]=p[dep][j];
		for(int j=1;j<=nn;j++) if(a[v][none[dep][j]]) none[dep+1][++nnn]=none[dep][j];
		bk(dep+1,rn+1,ppn,nnn);
		p[dep][i]=0;none[dep][++nn]=v;
	}
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		ans=0;
		memset(a,0,sizeof(a));
		for(int i=1;i<=m;i++)
		{
			int x,y;read(x),read(y);
			a[x][y]=a[y][x]=1;
		}
		for(int i=1;i<=n;i++) p[1][i]=i;
		bk(1,0,n,0);
		if(ans>1000) puts("Too many maximal sets of friends.");
		else cout<<ans<<endl;
	}
	return 0;
}

