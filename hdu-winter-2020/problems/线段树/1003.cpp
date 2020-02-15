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
#define ls id<<1
#define rs id<<1|1
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
using namespace std;
const int maxn=100050;
inline ll read()
{
    ll x=0,t=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')t=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*t;
}
int T,n,m,a[maxn];
struct tree{
    ll l,r,sum;
    ll tag;
}t[maxn<<2];
void pushdown(ll id)
{
    if(t[id].tag)
    {
        t[ls].tag=t[id].tag;
        t[rs].tag=t[id].tag;
        t[ls].sum=(t[ls].r-t[ls].l+1)*t[id].tag;
        t[rs].sum=(t[rs].r-t[rs].l+1)*t[id].tag;
        t[id].tag=0;
    }
}
void build(ll id,ll l,ll r)
{
    t[id].l=l;t[id].r=r;t[id].tag=0;
    if(l==r)
    {
        t[id].sum=1;
        return ;
    }
    ll mid=l+r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    t[id].sum=t[ls].sum+t[rs].sum;
}
void change(ll id,ll l,ll r,ll p)
{
    if(l<=t[id].l&&r>=t[id].r) 
    {
        t[id].sum=(t[id].r-t[id].l+1)*p;
        t[id].tag=p;
        return ;
    }
    pushdown(id);
    ll mid=t[id].l+t[id].r>>1;
    if(l<=mid) change(ls,l,r,p);
    if(r>mid) change(rs,l,r,p);
    t[id].sum=t[ls].sum+t[rs].sum;
}
ll query(ll id,ll l,ll r)
{
    if(l<=t[id].l&&r>=t[id].r) return t[id].sum;
    pushdown(id);
    ll mid=t[id].l+t[id].r>>1;
    ll res=0;
    if(l<=mid) res+=query(ls,l,r);
    if(r>mid) res+=query(rs,l,r);
    return res;
}
int main()
{
    cin>>T;
    for(int t=1;t<=T;t++)
    {
    	cin>>n>>m;
    	build(1,1,n);
    	while(m--)
    	{
    		int x,y,z;
    		read(x),read(y),read(z);
    		change(1,x,y,z);
		}
		cout<<"Case "<<t<<": The total value of the hook is "<<query(1,1,n)<<"."<<endl;
	}
    return 0;
}
