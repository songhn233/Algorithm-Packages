#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=650;
int n,m;
double f[maxn];
vector<int> e[maxn];
double ans=inf;
void calc(int p)
{
	for(int i=0;i<=n;i++) f[i]=0;
	for(int i=n-1;i>=1;i--)
	{
		int num=e[i].size();
		double maxx=0.0,sum=0.0;
		for(int j=0;j<e[i].size();j++)
		{
			int v=e[i][j];
			sum+=f[v];
			maxx=max(maxx,f[v]);
		}
		
		if(i==p&&num>1) sum-=maxx,num--;
		
		f[i]=(sum/(double)num)+1;
	}
	ans=min(ans,f[1]);
}
int main()
{
	read(n),read(m);
	for(int i=1;i<=m;i++)
	{
		int x,y;read(x),read(y);
		e[x].push_back(y);
	}
	for(int i=1;i<=n-1;i++) calc(i);
	printf("%.8lf\n",ans);
	return 0;
}

