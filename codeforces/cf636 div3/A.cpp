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
int T;
ll n,k;
bool calc(ll x)
{
    ll t=2;
    while(((1ll<<t)-1)<x) t++;
    if(x==((1ll<<t)-1)) return true;
    return false;
} 
int main()
{
    cin>>T;
    while(T--)
    {
        rd(n);
        ll ans=0;
        for(ll i=1;i<=n/i;i++)
        {
            if(n%i) continue;
            ll temp=n/i;
            if(calc(i))
            {
                ans=n/i;
                break;    
            }
            if(calc(n/i))
            {
                ans=i;
                break;
            }
        }
        if(ans==0)
        {
            if(calc(n)) ans=1;
        }
        cout<<ans<<endl;
    }
    return 0;
}