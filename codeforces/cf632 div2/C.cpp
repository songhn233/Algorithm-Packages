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
const int maxn=200050;
ll n,a[maxn],s[maxn];
ll a1[maxn],a2[maxn];
map<ll,ll> mp;
int main()
{
    cin>>n;
    rep(i,1,n) rd(a[i]);
    ll lim=0;
    ll ans=0;
    mp[0]=0;
    rep(i,1,n)
    {
        s[i]=s[i-1]+a[i];
        if(a[i]) ans++;
        if(s[i]==0) 
        {
            lim=max(lim,mp[s[i]]+1);
        }
        else if(mp[s[i]]) 
        {
            lim=max(lim,mp[s[i]]+1);
        }
        ans+=max(0ll,i-1-lim);
        mp[s[i]]=i;
    }
    cout<<ans<<endl;
    return 0;
}