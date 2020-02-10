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
#define PLL pair<ll,ll>
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=200050;
ll n,d,t,c[maxn];
PLL a[maxn];
int main()
{
	cin>>n>>d>>t;
	for(int i=1;i<=n;i++)
	{
		read(a[i].first);read(a[i].second);
	}
	sort(a+1,a+n+1);
	ll i=1;
	ll temp=0,ans=0;
	d*=2;
	while(i<=n)
	{
		temp-=c[i];
		a[i].second-=temp;
		if(a[i].second>0)
		{
			ll tt=(a[i].second+t-1)/t;
			ans+=tt;
			temp+=t*tt;
			int l=0,r=n+1;
			while(l<r)
			{
				int mid=l+r>>1;
				if(a[mid].first>a[i].first+d) r=mid;
				else l=mid+1;
			}
			if(l!=n+1) c[l]+=t*tt;
		}
		i++;
	}
	cout<<ans<<endl;
	return 0;
}

