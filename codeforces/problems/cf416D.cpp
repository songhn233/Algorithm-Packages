#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=50050;
int n,m,f[maxn][10],a[maxn][10];
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
int main()
{
	m=read(),n=read();
	for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) a[i][j]=read();
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		f[i][j]=max(f[i][j-1],f[i-1][j])+a[i][j];
	for(int i=1;i<=m;i++) cout<<f[i][n]<<" ";
	puts("");
	return 0;
}
