#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=300050;
const ll inf=1e18;
ll q,n,a[maxn],b[maxn],f[maxn][3];
inline ll read()
{
	ll x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
int main()
{
	q=read();
	while(q--)
	{
		n=read();
		for(int i=1;i<=n;i++) a[i]=read(),b[i]=read();
		for(int i=1;i<=n;i++) f[i][0]=f[i][1]=f[i][2]=inf;
		f[1][0]=0,f[1][1]=b[1],f[1][2]=2*b[1];
		for(int i=2;i<=n;i++)
		{
			for(int j=0;j<3;j++)
			{
				for(int k=0;k<3;k++)
				{
					if(a[i]+j!=a[i-1]+k) f[i][j]=min(f[i][j],f[i-1][k]+j*b[i]);
				}
			}
		}
		cout<<min(f[n][0],min(f[n][1],f[n][2]))<<endl;
	}
	return 0;
} 
