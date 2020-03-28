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
ll a,b,c,k;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(!b)
    {
        x=1,y=0;
        return a;
    }
    ll d=exgcd(b,a%b,x,y);
    ll t=x;
    x=y;
    y=t-(a/b)*y;
    return d;
}
int main()
{
    ll x,y,z;
    cin>>a>>b>>c>>k;
    ll d=exgcd(a,b,x,y);
    rep(i,0,d)
    {
        if(k-i*c<0) break;
        if((k-i*c)%d) continue;
        x*=(k-i*c)/d;
        x=(x%(b/d)+(b/d))%(b/d);
        z=i;
        y=(k-i*c-x*a)/b;
        break;
    }
    cout<<x<<" "<<y<<" "<<z<<endl;
    return 0;
}