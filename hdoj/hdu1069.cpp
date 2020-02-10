#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=200;
int n,mp[maxn][maxn],dp[maxn],T;
struct node{
	int a,b,c;
}q[maxn];
int f(int x)
{
	if(dp[x]) return dp[x];
	dp[x]=q[x].c;
	for(int i=1;i<=6*n;i++)
	{
		if(mp[x][i]==0) continue;
		dp[x]=max(dp[x],q[x].c+f(i));
	}
	return dp[x];
}
int main()
{
	while(cin>>n)
	{
		if(n==0) break;
		T++;
		memset(mp,0,sizeof(mp));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++) 
		{
			cin>>q[i].a>>q[i].b>>q[i].c;
			int a=q[i].a,b=q[i].b,c=q[i].c;
			q[n+i]={a,c,b};q[n*2+i]={b,a,c};
			q[n*3+i]={b,c,a};q[n*4+i]={c,a,b};q[n*5+i]={c,b,a};	
		}
		for(int i=1;i<=6*n;i++)
		{
			for(int j=i+1;j<=6*n;j++)
			{
				if((q[i].a>q[j].a&&q[i].b>q[j].b)||(q[i].a>q[j].b&&q[i].b>q[j].a)) mp[i][j]=1;
				else if((q[i].a<q[j].a&&q[i].b<q[j].b)||(q[i].a<q[j].b&&q[i].b<q[j].a)) mp[j][i]=1;
			}
		}
		int ans=0;
		for(int i=1;i<=6*n;i++) ans=max(ans,f(i));
		printf("Case %d: maximum height = %d\n",T,ans);
	}
	return 0;
}
