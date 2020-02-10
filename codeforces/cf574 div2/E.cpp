#include<cstdio>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=3010;
ll f[maxn][maxn],g[maxn*maxn],q[maxn],h[maxn][maxn];
ll n,m,a,b,x,y,z;
ll ans=0;
int main()
{
	cin>>n>>m>>a>>b;
	cin>>g[0]>>x>>y>>z;
	for(int i=1;i<=n*m;i++) g[i]=(g[i-1]*x+y)%z;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) f[i][j]=g[(i-1)*m+j-1];
	for(int i=1;i<=n;i++)
	{
		int hh=1,tt=0;
		for(int j=1;j<=m;j++)
		{
			if(hh<=tt&&j-b+1>q[hh]) hh++;
			while(hh<=tt&&f[i][q[tt]]>=f[i][j]) tt--;
			q[++tt]=j;
			h[i][j]=f[i][q[hh]];
		}
	}
	for(int i=b;i<=m;i++)
	{
		int hh=1,tt=0;
		for(int j=1;j<=n;j++)
		{
			if(hh<=tt&&j-a+1>q[hh]) hh++;
			while(hh<=tt&&h[q[tt]][i]>=h[j][i]) tt--;
			q[++tt]=j;
			if(j>=a) ans+=h[q[hh]][i];
		}
	}
	cout<<ans<<endl;
	return 0;
}
