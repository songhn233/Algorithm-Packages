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
const ll p=998244353;
const int maxn=5050;
const int N=5000;
ll T,x,y,t;
ll fac[maxn];
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
    if(n<m) return 0;
    return (fac[n]*ksm(fac[m],p-2)%p*ksm(fac[n-m],p-2)%p)%p;
}
int main()
{
    cin>>T;
    fac[0]=fac[1]=1;
    rep(i,1,N) fac[i]=(fac[i-1]*i)%p;
    while(T--)
    {
        cin>>x>>y>>t;
        cout<<(c(t,x+y)*c(x+y,x))%p<<endl;
    }
    return 0;
}