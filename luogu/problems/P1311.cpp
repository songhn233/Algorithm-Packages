#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=200050;
int n,k,p;
int c[maxn],w[maxn],pre[maxn],sum[maxn],cnt[maxn],pos=0;
int main()
{
	cin>>n>>k>>p;
	for(int i=1;i<=n;i++) cin>>c[i]>>w[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(w[i]<=p) pos=i;
		if(pre[c[i]]<=pos) sum[c[i]]=cnt[c[i]];
		ans+=sum[c[i]];
		cnt[c[i]]++;
		pre[c[i]]=i;
	}
	cout<<ans<<endl;
	return 0;
}
