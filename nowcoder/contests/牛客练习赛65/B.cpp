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
const int maxn=2050;
ll n,m,k,p;
ll a[maxn][maxn],s[maxn];
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
int main()
{
    cin>>n>>m>>k>>p;
    rep(i,1,n)
    {
        s[i]=0;
        rep(j,1,m)
        {
            rd(a[i][j]);
            ll temp=a[i][j];
            ll cnt=0;
            while(temp>1) temp/=k,cnt++;
            s[i]+=cnt;
        }
    }
    ll maxx=0;
    rep(i,1,n)
    {
        if(s[i]>maxx)
        {
            maxx=s[i];
        }
    }
    ll ans=ksm(k,maxx);
    cout<<ans%p<<endl;
    return 0;
}