#include<cstdio>
#include<algorithm>
#include<iostream>
#define ll long long
using namespace std;
const int maxn=100010;
int n,a[3][maxn];
ll f[maxn][3];
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[1][i]=read();
	for(int i=1;i<=n;i++) a[2][i]=read();
	f[1][0]=0;f[1][1]=a[1][1];f[1][2]=a[2][1];
	for(int i=2;i<=n;i++)
	{
		f[i][0]=max(f[i-1][0],max(f[i-1][1],f[i-1][2]));
		f[i][1]=max(f[i-1][0],f[i-1][2])+a[1][i];
		f[i][2]=max(f[i-1][0],f[i-1][1])+a[2][i];
	}
	ll ans=max(f[n][0],max(f[n][1],f[n][2]));
	cout<<ans<<endl;
	return 0;
}
