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
ll s1[maxn],s2[maxn];
ll c1[maxn],c2[maxn];
ll T,n,w[maxn],v[maxn],m;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        rep(i,0,n+1) c1[i]=c2[i]=s1[i]=s2[i]=v[i]=w[i]=0;
        ll ans=0;
        rep(i,1,n)
        {
            rd(w[i]);
            s1[i]=s1[i-1]+w[i];
            ll t;rd(t);
            if(t)
            {
                ll x;rd(x);
                v[i]=x;
            }
            c1[i]=c1[i-1]+v[i];
        }
        dep(i,n,1)
        {
            s2[i]=s2[i+1]+w[i];
            c2[i]=c2[i+1]+v[i];
        }
        rep(i,1,n)
        {
            if(s1[i]>m) break;
            ll temp=m-s1[i];
            ll l=i+1,r=n;
            while(l<r)
            {
                ll mid=l+r>>1;
                if(s2[mid]<=temp) r=mid;
                else l=mid+1;
            }
            if(s2[l]<=temp&&l>=i+1)
            {
                ans=max(ans,c1[i]+c2[l]);
            }
        }
        rep(i,1,n)
        {
            if(s1[i]<=m) ans=max(ans,c1[i]);
        }
        dep(i,n,1) 
        {
            if(s2[i]<=m) ans=max(ans,c2[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}