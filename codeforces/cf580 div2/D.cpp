#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int n,t[200][2],a[200][200],d[200][200];
int mp[100050],num;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		ll x;scanf("%I64d",&x);
		if(x==0) continue;
		for(int j=0;j<=60;j++)
		{
			if(x>>j&1)
			{
				if(t[j][0]==0) t[j][0]=i;
				else if(t[j][1]==0) t[j][1]=i;
				else 
				{
					puts("3");
					return 0;
				}
			}
		}
	}
	memset(a,0x3f,sizeof(a));
	for(int i=0;i<=60;i++)
	{
		if(t[i][0]&&t[i][1])
		{
			int x=t[i][0],y=t[i][1];
			int t1,t2;
			if(mp[x]) t1=mp[x];else t1=mp[x]=++num;
			if(mp[y]) t2=mp[y];else t2=mp[y]=++num;
			a[t1][t2]=a[t2][t1]=1;
		}
	}
	for(int i=1;i<=num;i++) a[i][i]=0;
	memcpy(d,a,sizeof(a));
	int ans=inf;
	n=num;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<k;i++)
		{
			for(int j=i+1;j<k;j++)
			{
				if((long long)a[i][k]+a[j][k]+d[i][j]<ans) ans=a[i][k]+a[j][k]+d[i][j];
			}
		}
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	}
	if(ans==inf) puts("-1");
	else cout<<ans<<endl;
	return 0;
}
