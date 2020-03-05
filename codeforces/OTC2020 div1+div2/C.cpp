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
const int maxn=200050;
int n,m;
ll a[maxn];
map<int,int> mp;
ll ksm(ll a,ll b)
{
	ll res=1%m;
	while(b)
	{
		if(b&1) res=res*a%m;
		a=a*a%m;
		b>>=1;
	}
	return res;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	ll ans=1;
	if(m==1)
	{
		puts("0");
		return 0;
	}
	for(int i=n;i>=1;i--)
	{
		ll temp=a[i]%m;
		mp[temp]++;
		for(int j=0;j<m;j++)
		{
			ll p=mp[j];
			if(mp[j]==0) continue;
			if(j==temp)
			{
				if(mp[j]>1)
				{
					puts("0");
					return 0;
				}
				else continue;
			}
			ans=(ans*ksm((((temp-j)%m+m)%m),mp[j]))%m;
		}
	}
	cout<<ans<<endl;
	return 0;
}

