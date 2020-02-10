#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1000005;
const int inf=0x3f3f3f3f;
int n,m,a[maxn];
int f[maxn][2];
int main()
{
	while(cin>>m>>n)
	{
		for(int i=0;i<=m;i++) f[i][0]=f[i][1]=-inf;
		f[0][0]=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=min(i,m);j>=1;j--)
			{
				f[j][0]=max(f[j][1],f[j][0]);
				f[j][1]=max(f[j][1],max(f[j-1][0],f[j-1][1]))+a[i];
			}
		}
		int ans=-inf;
		cout<<max(f[m][0],f[m][1])<<endl;
	}
	return 0;
}
