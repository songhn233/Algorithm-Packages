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
ll n,k,sum[maxn];
map<ll,ll> mp;
ll ans;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) read(sum[i]);
	for(int i=1;i<=n;i++) sum[i]+=sum[i-1];
	mp[0]=1;
	for(int i=1;i<=n;i++)
	{
		if(i>=k) mp[(sum[i-k]-(i-k))%k]--;
		ans+=mp[(sum[i]-i)%k];
		mp[(sum[i]-i)%k]++;
	}
	cout<<ans<<endl;
	return 0;
}

