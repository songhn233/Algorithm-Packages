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
const int maxn=100050;
const int inf=0x3f3f3f3f;
ll T,n,a[maxn],m,l[maxn],val[maxn];
vector<pair<ll,ll> >ans[maxn];
map<ll,ll> mp;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int main()
{
    rd(T);
    for(int tt=1;tt<=T;tt++)
    {
        printf("Case #%d:\n",tt);
        mp.clear();
        rd(n);
        memset(l,0,sizeof(l));memset(val,0,sizeof(val));
        for(ll i=1;i<=n;i++) ans[i].clear();
        for(ll i=1;i<=n;i++) rd(a[i]);
        for(ll i=1;i<=n;i++)
        {
            ll j;
            for(val[i]=a[i],j=l[i]=i;j;j=l[j]-1)
            {
                val[j]=gcd(val[j],a[i]);
                while(l[j]>1&&gcd(a[i],val[l[j]-1])==gcd(a[i],val[j]))
                    l[j]=l[l[j]-1];
                ans[i].push_back(make_pair(l[j],val[j]));
                mp[val[j]]+=j-l[j]+1;
            }
        }
        rd(m);
        ll l,r;
        while(m--)
        {
            rd(l),rd(r);
            for(ll i=0;i<ans[r].size();i++)
                if(l>=ans[r][i].first)
                {
                    printf("%lld %lld\n",ans[r][i].second,mp[ans[r][i].second]);
                    break;
                }
        }
    }
    return 0;
}