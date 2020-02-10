#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=2010;
int n,k,a[maxn][maxn];
char c[maxn][maxn];
void add(int x1,int y1,int x2,int y2)
{
	a[x1][y1]++;a[x2+1][y2+1]++;
	a[x1][y2+1]--;a[x2+1][y1]--;
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>(c[i]+1);
	for(int i=1;i<=n;i++)
	{
		int s=0,e=0;
		for(int j=1;j<=n;j++)
		{
			if(c[i][j]=='B')
			{
				if(s==0) s=j;
				e=j;
			}
		}
		if(s==0) add(1,1,n,n);
		if(e-s+1<=k) add(max(1,i-k+1),max(1,e-k+1),i,s);
	}
	for(int i=1;i<=n;i++)
	{
		int s=0,e=0;
		for(int j=1;j<=n;j++)
		{
			if(c[j][i]=='B') 
			{
				if(s==0) s=j;
				e=j;
			}
		}
		if(s==0) add(1,1,n,n);
		if(e-s+1<=k) add(max(e-k+1,1),max(i-k+1,1),s,i);
	}
	int ans=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) ans=max(ans,a[i][j]);
	cout<<ans<<endl;
	return 0;
}
