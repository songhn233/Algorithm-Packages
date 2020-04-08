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
const int maxn=200050;
const ll p=998244353;
ll n,k;
ll a[maxn],b[maxn],n1,n2;
ll f[maxn][2];
void init()
{
    f[1][0]=k-1,f[1][1]=k-2;
    rep(i,2,max(n1,n2))
    {
        f[i][0]=((k-1)*f[i-1][1])%p;
        f[i][1]=(f[i-1][0]+(k-2)*f[i-1][1])%p;
    }
}
ll ksm(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=(res*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return res;
}
ll calc(ll a[],ll n)
{
    rep(i,2,n)  if(a[i]==a[i-1]&&a[i]!=-1) return 0;
    ll l1,l2;
    ll l,r;
    l=r=1;
    ll ans=1;
    while(r<=n)
    {
        while(l<=n&&a[l]!=-1) l++;
        r=l;
        while(r<=n&&a[r]==-1) r++;
        if(l==1&&r==n+1) ans=(k*ksm(k-1,n-1))%p;
        else if(l==1||r==n+1) ans=(ans*ksm(k-1,r-l))%p;
        else if(a[l-1]==a[r]) ans=(ans*f[r-l][0])%p;
        else ans=(ans*f[r-l][1])%p;
        l=r;
    }
    return ans;
}
int main()
{
    cin>>n>>k;
    rep(i,1,n)
    {
        int x;rd(x);
        if(i&1) a[++n1]=x;
        else b[++n2]=x;
    }
    init();
    cout<<(calc(a,n1)*calc(b,n2))%p<<endl;
    return 0;
}