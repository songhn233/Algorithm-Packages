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
const ll inf=1e15;
const int maxn=200050;
ll n,k,a[maxn];
ll s1[maxn],s2[maxn];
map<ll,ll> mp;
int main()
{
    cin>>n>>k;
    rep(i,1,n) rd(a[i]),mp[a[i]]++;
    sort(a+1,a+n+1);
    rep(i,1,n) s1[i]=s1[i-1]+a[i];
    dep(i,n,1) s2[i]=s2[i+1]+a[i];
    for(auto x:mp)
    {
        if(x.second>=k)
        {
            puts("0");
            return 0;
        }
    }
    ll ans=inf;
    rep(i,1,n)
    {
        if(i>=k) ans=min(ans,i*a[i]-s1[i]-(i-k));
        if(n-i+1>=k) ans=min(ans,s2[i]-(n-i+1)*a[i]-(n-i+1-k));
        ans=min(ans,i*a[i]-s1[i]+s2[i]-(n-i+1)*a[i]-(n-k));
    }
    cout<<ans<<endl;
    return 0;
}