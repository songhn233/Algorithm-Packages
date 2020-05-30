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
const int maxn=500050;
const ll p=998244353;
ll n,k,fac[maxn];
ll ksm(ll a,ll b)
{
    ll res=1%p;
    while(b)
    {
        if(b&1) res=(res*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return res;
}
ll c(ll n,ll m)
{
    return ((fac[n]%p*ksm(fac[m],p-2)%p)*ksm(fac[n-m],p-2)%p)%p;
}
int main()
{
    cin>>n>>k;
    if(k>n) puts("0");
    else if(k==n) puts("1");
    else
    {
        fac[0]=fac[1]=1;
        for(int i=1;i<=n;i++) fac[i]=(fac[i-1]*i)%p;
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            ll t=(n/i)-1;
            if(t<k-1) continue;
            ans=(ans+c(t,k-1))%p;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}