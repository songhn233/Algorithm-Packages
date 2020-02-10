#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=1005;
const int p=1e9+7;
int n,m,a[maxn][maxn];
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
ll ksm(ll a,ll b)
{
	ll res=1%p;
	while(b)
	{
		if(b&1) res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
int main()
{
	n=read(),m=read();
	memset(a,-1,sizeof(a));
	for(int i=1;i<=n;i++)
	{
		int x;x=read();
		for(int j=1;j<=x;j++) a[i][j]=1;
		a[i][x+1]=0;
	}
	for(int i=1;i<=m;i++)
	{
		int x;x=read();
		for(int j=1;j<=x;j++) 
		{
			if(a[j][i]==0)
			{
				puts("0");
				return 0;
			}
			a[j][i]=1;
		}
		if(a[x+1][i]==1) 
		{
			puts("0");
			return 0;
		}
		a[x+1][i]=0;
	}
	ll temp=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(a[i][j]==-1) temp++;
	//cout<<temp<<endl;
	cout<<ksm(2ll,temp)<<endl;
	return 0;
}
