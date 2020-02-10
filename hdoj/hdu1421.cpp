#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=2050;
int n,k,a[maxn],f[maxn][maxn];
int main()
{
	while(cin>>n>>k)
	{
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		memset(f,0x3f,sizeof(f));
		for(int i=0;i<=n;i++) f[i][0]=0;
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=k;j++)
			{
				f[i][j]=f[i-1][j];
				f[i][j]=min(f[i][j],f[i-2][j-1]+(a[i]-a[i-1])*(a[i]-a[i-1]));
			}
		}
		cout<<f[n][k]<<endl;
	}
	return 0;
}
