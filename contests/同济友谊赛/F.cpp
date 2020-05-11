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
ll n,m,c[maxn];
struct node{
    ll id,val;
    bool operator<(const node&t) const{
        return val>t.val;
    }
}a[maxn];
ll ans[maxn],s[maxn];
PII q[maxn];
int main()
{
    rd(n),rd(m);
    for(int i=1;i<=m;i++)
    {
        ll l,r;rd(l),rd(r);
        c[l]++,c[r+1]--;
        q[i].first=l,q[i].second=r;
    }
    for(int i=1;i<=n;i++) 
    {
        c[i]+=c[i-1];
        a[i].id=i;
        a[i].val=c[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) ans[a[i].id]=n-i+1;
    for(int i=1;i<=n;i++) s[i]=s[i-1]+ans[i];
    ll ans=0;
    for(int i=1;i<=m;i++)
    {
        int l=q[i].first,r=q[i].second;
        ans+=s[r]-s[l-1];
    }
    cout<<ans<<endl;
    return 0;
}