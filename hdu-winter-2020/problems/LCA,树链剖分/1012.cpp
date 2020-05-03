// hdu5443
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define ls id<<1
#define rs id<<1|1
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
int T,n,m,a[maxn];
struct tree{
    ll l,r,maxx;
}t[maxn<<2];
void build(ll id,ll l,ll r)
{
    t[id].l=l;t[id].r=r;t[id].maxx=0;
    if(l==r)
    {
        t[id].maxx=a[l];
        return ;
    }
    ll mid=l+r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    t[id].maxx=max(t[ls].maxx,t[rs].maxx);
}
ll query(ll id,ll l,ll r)
{
    if(l<=t[id].l&&r>=t[id].r) return t[id].maxx;
    ll mid=t[id].l+t[id].r>>1;
    ll res=0;
    if(l<=mid) res=max(res,query(ls,l,r));
    if(r>mid) res=max(res,query(rs,l,r));
    return res;
}
int main()
{
    cin>>T;
    while(T--)
    {
        rd(n);
        rep(i,1,n) rd(a[i]);
        build(1,1,n);
        rd(m);
        while(m--)
        {
            int x,y;
            rd(x),rd(y);
            printf("%d\n",query(1,x,y));
        }
    }
    return 0;
}