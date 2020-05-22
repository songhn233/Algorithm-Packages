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
const ll mod=998244353;
int n;
ll s[maxn],h[maxn];
int main()
{
    cin>>n;
    for(int i=1;i<=100000;i++)
    {
        if(i&1) h[i]=1;
        else h[i]=2*h[i/2];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i/j;j++)
        {
            if(i%j==0) s[i]=(s[i]+h[j])%mod;
            if(i%(i/j)==0&&(j!=i/j)) s[i]=(s[i]+h[i/j])%mod;
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++) ans=(ans+s[i])%mod;
    cout<<ans<<endl;
    return 0;
}