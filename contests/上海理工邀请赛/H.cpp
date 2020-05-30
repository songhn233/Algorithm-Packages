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
const int maxn=550;
const int maxm=300010;
ll n,m,k;
ll a[maxn][maxn];
ll r[maxn],c[maxn];
const ll p=998244353;
int main()
{
    cin>>n>>m>>k;
    rep(i,1,n) rep(j,1,m) rd(a[i][j]);
    rep(i,1,k)
    {
        char opt[5];
        ll p,t;
        cin>>opt>>p>>t;
        if(opt[0]=='r') r[p]=t;
        else c[p]=t;
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            ans=(ans+(a[i][j]%p)*(max(r[i],c[j])%p)%p)%p;
        }
    }
    cout<<ans<<endl;
    return 0;
}
