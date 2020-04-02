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
#define PLL pair<ll,ll>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
template<class T>inline void rd(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const ll inf=2e18;
ll n,b;
vector<PLL> p;
int main()
{
    cin>>n>>b;
    for(ll i=2;i<=b/i;i++)
    {
        if(b%i==0)
        {
            ll t=0;
            while(b%i==0) t++,b/=i;
            p.push_back(make_pair(i,t));
        }
    }
    if(b>1) p.push_back(make_pair(b,1));
    ll ans=inf;
    for(int i=0;i<p.size();i++)
    {
        ll x=p[i].first,cnt=p[i].second;
        ll temp=n,tot=0;
        while(temp)
        {
            tot+=temp/x;
            temp/=x;
        }
        ans=min(ans,tot/cnt);
    }
    cout<<ans<<endl;
    return 0;
}