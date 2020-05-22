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
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
template<class T>inline void rd(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=100050;
ll n,a[maxn],p;
int main()
{
	rd(n);rd(p);
	rep(i,1,n) rd(a[i]);
	sort(a+1,a+n+1);
	ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        ll x=p,y=a[i];
        if(x<y) swap(x,y);
        ll t1=x-y;ll t2=y+x;
        ll n1=upper_bound(a+1,a+n+1,t1)-a;
        ll n2=lower_bound(a+1,a+n+1,t2)-a-1;
        if(n2>i&&n2-n1+1>=1) 
        {
            if(i>=n1) ans+=n2-i;
            else ans+=n2-n1+1;
        }
    }
	cout<<ans<<endl;
	return 0;
}