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
const int N=100000;
ll T;
ll s[maxn];
ll n,l,r;
ll calc(ll x)
{
    if(x>s[n]) return 1;
    ll temp=lower_bound(s+1,s+n+1,x)-s;
    ll t=x-s[temp-1];
    if(t&1) return temp;
    else return (temp+t/2);
}
int main()
{
    cin>>T;
    while(T--)
    {
        rd(n),rd(l),rd(r);
        s[0]=0;
        rep(i,1,n) s[i]=s[i-1]+2*(n-i);
        rep(i,l,r) cout<<calc(i)<<" ";
        cout<<endl;
    }
    return 0;
}