#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define ls id<<1
#define rs id<<1|1
using namespace std;
const int maxn=100050;
const ll inf=1e15;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
int n,m,a[maxn],q;
struct tree{
    ll l,r,minx;
    ll tag;
}t[maxn<<2];
void pushdown(ll id)
{
    if(t[id].tag)
    {
        t[ls].tag+=t[id].tag;
        t[rs].tag+=t[id].tag;
        t[ls].minx+=t[id].tag;
        t[rs].minx+=t[id].tag;
        t[id].tag=0;
    }
}
void build(ll id,ll l,ll r)
{
    t[id].l=l;t[id].r=r;t[id].tag=0;
    if(l==r)
    {
        t[id].minx=a[l];
        return ;
    }
    ll mid=l+r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    t[id].minx=min(t[ls].minx,t[rs].minx);
}
void change(ll id,ll l,ll r,ll p)
{
    if(l<=t[id].l&&r>=t[id].r) 
    {
        t[id].minx+=p;
        t[id].tag+=p;
        return ;
    }
    pushdown(id);
    ll mid=t[id].l+t[id].r>>1;
    if(l<=mid) change(ls,l,r,p);
    if(r>mid) change(rs,l,r,p);
    t[id].minx=min(t[ls].minx,t[rs].minx);
}
ll query(ll id,ll l,ll r)
{
    if(l<=t[id].l&&r>=t[id].r) return t[id].minx;
    pushdown(id);
    ll mid=t[id].l+t[id].r>>1;
    ll res=inf;
    if(l<=mid) res=min(res,query(ls,l,r));
    if(r>mid) res=min(res,query(rs,l,r));
    return res;
}
struct node{
	int l,r;
	bool operator<(const node&t) const{
		if(r!=t.r) return r<t.r;
		else return l>t.l;
	}
}e[maxn];
int main()
{
    cin>>n>>q;
    for(int i=1;i<n;i++) read(a[i]);
    build(1,1,n-1);
    ll ans=0;
    for(int i=1;i<=q;i++)
    {
    	int x,y;read(x),read(y);
    	if(x>y) swap(x,y);
    	if(x==y) continue;
    	e[i]={x,y};
	}
	sort(e+1,e+q+1);
    for(int i=1;i<=q;i++)
    {
    	int s=e[i].l,t=e[i].r;
    	ll temp=query(1,s+1,t);
    	ans+=temp;
    	change(1,s+1,t,-temp);
	}
	cout<<ans<<endl;
    return 0;
}
