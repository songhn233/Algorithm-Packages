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
const int maxn=1050;
int n;
ll x[maxn],y[maxn];
map<pair<ll,ll>,set<ll> > mp;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll ans=0,num=0;
int main()
{
    cin>>n;
    rep(i,1,n) rd(x[i]),rd(y[i]);
    rep(i,1,n)
    {
        rep(j,i+1,n)
        {
            ll xx=x[i]-x[j],yy=y[i]-y[j];
            ll temp=x[i]*y[j]-x[j]*y[i];
            ll t=gcd(xx,yy);
            xx/=t,yy/=t,temp/=t;
            if(!mp[make_pair(xx,yy)].count(temp))
            {
                mp[make_pair(xx,yy)].insert(temp);
                num++;
                ans+=num-mp[make_pair(xx,yy)].size();
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}