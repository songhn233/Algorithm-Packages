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
const int maxn=350;
const ll mod=1e9+7;
ll n,k,f[maxn][maxn];
int main()
{
    cin>>n>>k;
    rep(i,1,n-1)
    {
        int x,y;rd(x),rd(y);
    }
    f[0][0]=1;
    rep(i,1,n)
    {
        rep(j,1,k)
        {
            f[i][j]=(f[i][j]+f[i-1][j]+f[i-1][j-1]*(k-j+1))%mod;
        }
    }
    ll ans=0;
    rep(i,1,k) ans=(ans+f[n][i])%mod;
    cout<<ans<<endl;
    return 0;
}