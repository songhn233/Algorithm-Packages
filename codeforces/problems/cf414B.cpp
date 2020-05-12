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
const ll p=1e9+7;
ll f[maxn][maxn],n,k;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) f[1][i]=1;
    for(int i=2;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int l=1;l*j<=n;l++)
                f[i][l*j]=(f[i][l*j]+f[i-1][j])%p;
        }
    }
    ll ans=0;
    rep(i,1,n) ans=(ans+f[k][i])%p;
    cout<<ans<<endl;
    return 0;
}