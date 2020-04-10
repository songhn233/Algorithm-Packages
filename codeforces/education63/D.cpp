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
const int maxn=300050;
ll f[maxn][3];
ll n,x;
ll a[maxn];
int main()
{
    cin>>n>>x;
    rep(i,1,n) rd(a[i]);
    mst(f,0xcf);
    f[0][0]=0;
    rep(i,1,n)
    {
        f[i][0]=max(f[i-1][0]+a[i],a[i]);
        f[i][1]=max(f[i-1][0]+x*a[i],max(f[i-1][1]+x*a[i],x*a[i]));
        f[i][2]=max(f[i-1][2]+a[i],f[i-1][1]+a[i]);
    }
    ll ans=0;
    rep(i,1,n) ans=max(ans,max(f[i][0],max(f[i][1],f[i][2])));
    cout<<ans<<endl;
    return 0;
}