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
const int maxn=40050;
int T;
ll a,b,q;
ll l,r;
ll s[maxn];
ll calc(ll x)
{
    if(x==0) return 0;
    if(x<=a*b) return s[x];
    ll t=x%(a*b);
    ll res=s[t];
    res+=(x/(a*b))*s[a*b];
    return res;
}
int main()
{
    cin>>T;
    while(T--)
    {
        rd(a),rd(b),rd(q);
        mst(s,0);
        for(ll i=0;i<=a*b;i++)
        {
            if(((i%a)%b)!=((i%b)%a)) s[i]++;
            if(i>0) s[i]+=s[i-1];
        }
        while(q--)
        {
            rd(l),rd(r);
            cout<<calc(r)-calc(l-1)<<" ";
        }
        cout<<endl;
    }
    return 0;
}