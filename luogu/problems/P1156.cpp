#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=250;
int f[maxn][maxn];
int n,m;
struct node{
	int t,h,f;
	bool operator<(const node&p)
	{
		if(t==p.t) return t<p.t;
	}
}a[maxn];
int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++) cin>>a[i].t>>a[i].f>>a[i].h;
	sort(a+1,a+n+1);
	memset(f,-1,sizeof(f));
	f[0][0]=10;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(f[i-1][j]>=a[i].t-a[i-1].t)
			{
				if(j+a[i].h>=m) 
				{
					cout<<a[i].t<<endl;
					return 0;
				}
				f[i][j+a[i].h]=max(f[i][j+a[i].h],f[i-1][j]-a[i].t+a[i-1].t);
				f[i][j]=max(f[i][j],f[i-1][j]-a[i].t+a[i-1].t+a[i].f);
			}
		}
	}
	int ans=10;
	for(int i=1;i<=n;i++)
	{
		if(ans<a[i].t) break;
		ans+=a[i].f;
	}
	cout<<ans<<endl;
	return 0;
}
