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
int n;
ll s[maxn],a[maxn];
map<ll,ll> mp;
int main()
{
	cin>>n;
    ll ans=0;
	for(int i=1;i<=n;i++)
	{
		int x;read(x);
		a[i]=x;
        if(x==0) ans++;
		s[i]=x^s[i-1];
	}
	for(int i=2;i<=n;i++)
	{
		ll temp=s[i-1]^a[i];
		if(temp==0) ans++;
		ans+=mp[temp];
		mp[s[i-1]]++;
	}
	cout<<ans<<endl;
	return 0;
}

