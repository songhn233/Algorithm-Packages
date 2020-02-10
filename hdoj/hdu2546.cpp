#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1050;
int n,m,v[maxn],f[maxn];
int main()
{
	while(cin>>n)
	{
		if(n==0) break;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++) cin>>v[i];
		cin>>m;
		if(m<5)
		{
			cout<<m<<endl;
			continue;
		}
		sort(v+1,v+n+1);
		int maxx=v[n];
		m-=5;
		for(int i=1;i<=n-1;i++)
		{
			for(int j=m;j>=v[i];j--)
			f[j]=max(f[j],f[j-v[i]]+v[i]);
		}
		int ans=5+m-f[m];
		ans-=maxx;
		cout<<ans<<endl;
	}
	return 0;
}
