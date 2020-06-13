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
const int maxn=1000005;
int T;
ll t[maxn];
ll calc(int n)
{
    ll ans=n+1;
    for(ll i=2;i<=n/i;i++)
    {
        if(n%i==0)
        {
            ans+=i;
            ans+=n/i;
            if(i==n/i) ans-=i;
        }
    }
    return ans;
}
int main()
{
    cin>>T;
    for(int i=1;i<=1000000;i++)
    {
        for(int j=i;j<=1000000;j+=i) t[j]=t[j]+i;
    }
    for(int i=1;i<=1000000;i++) t[i]+=t[i-1];
    while(T--)
    {
        int l,r;
        rd(l),rd(r);
        printf("%lld\n",t[r]-t[l-1]);
    }
    return 0;
}