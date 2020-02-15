#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define mst(a,b) memset((a),(b),sizeof(a))
#define PII pair<int,int>
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=100050;
ll T,a[maxn],n;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		int pan=0;
		for(int i=1;i<=n;i++) read(a[i]);
		map<ll,ll> mp;mp.clear();
		for(int i=1;i<=n;i++)
		{
			if(a[i]==-1)
			{
				if(a[i+1]!=-1&&i+1<=n)
				{
					pan=1;
					mp[a[i+1]]=1;
				}
				if(a[i-1]!=-1&&i-1>=1)
				{
					pan=1;
					mp[a[i-1]]=1;
				}
			}
		}
		if(pan==0)
		{
			puts("0 0");
			continue;
		}
		ll res=0,minx=inf,maxx=-inf;
		for(auto x:mp)
		{
			minx=min(minx,x.first);
			maxx=max(maxx,x.first);
		}
		res=(minx+maxx)/2;
		ll ans=max(abs(res-minx),abs(res-maxx));
		for(int i=1;i<n;i++)
		{
			if(a[i]!=-1&&a[i+1]!=-1)
			{
				ans=max(ans,abs(a[i+1]-a[i]));
			}
		}
		cout<<ans<<" "<<res<<endl;
	}
	return 0;
}
