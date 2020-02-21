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
const int maxn=100050;
int T,a[maxn],n,q;
struct tree{
	int l,r;
	int lmax,rmax,maxx;
}t[maxn<<2];
void build(int id,int l,int r)
{
	t[id].l=l;t[id].r=r;t[id].lmax=t[id].rmax=t[id].maxx=0;
	if(l==r)
	{
		t[id].lmax=t[id].rmax=t[id].maxx=1;
		return ;
	}
	int mid=l+r>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[id].maxx=max(t[ls].maxx,t[rs].maxx);
	if(a[t[ls].r]<a[t[rs].l]) t[id].maxx=max(t[id].maxx,t[ls].rmax+t[rs].lmax);
	t[id].lmax=t[ls].lmax;t[id].rmax=t[rs].rmax;
	if(t[ls].lmax==t[ls].r-t[ls].l+1) 
	{
		if(a[t[ls].r]<a[t[rs].l])
		{
			t[id].lmax=max(t[id].lmax,t[ls].r-t[ls].l+1+t[rs].lmax);
		}
	}
	if(t[rs].rmax==t[rs].r-t[rs].l+1) 
	{
		if(a[t[ls].r]<a[t[rs].l])
		{
			t[id].rmax=max(t[id].rmax,t[rs].r-t[rs].l+1+t[ls].rmax);
		}
	}
}
void change(int id,int x,int p)
{
	if(t[id].l==t[id].r)
	{
		a[t[id].l]=p;
		return ;
	}
	int mid=t[id].l+t[id].r>>1;
	if(x<=mid) change(ls,x,p);
	else change(rs,x,p);
	t[id].maxx=max(t[ls].maxx,t[rs].maxx);
	if(a[t[ls].r]<a[t[rs].l]) t[id].maxx=max(t[id].maxx,t[ls].rmax+t[rs].lmax);
	t[id].lmax=t[ls].lmax;t[id].rmax=t[rs].rmax;
	if(t[ls].lmax==t[ls].r-t[ls].l+1) 
	{
		if(a[t[ls].r]<a[t[rs].l])
		{
			t[id].lmax=max(t[id].lmax,t[ls].r-t[ls].l+1+t[rs].lmax);
		}
	}
	if(t[rs].rmax==t[rs].r-t[rs].l+1) 
	{
		if(a[t[ls].r]<a[t[rs].l])
		{
			t[id].rmax=max(t[id].rmax,t[rs].r-t[rs].l+1+t[ls].rmax);
		}
	}
}
int query(int id,int l,int r)
{
	if(l<=t[id].l&&r>=t[id].r)
	{
		return t[id].maxx;
	}
	int res=0;
	int mid=t[id].l+t[id].r>>1;
	if(l<=mid) res=max(res,query(ls,l,r));
	if(r>mid) res=max(res,query(rs,l,r));
	if(a[t[ls].r]<a[t[rs].l]&&l<=mid&&r>mid)
	{
		res=max(res,min(t[ls].rmax,mid-l+1)+min(t[rs].lmax,r-mid));
	}
	return res;
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>q;
		for(int i=0;i<n;i++) read(a[i]);
		build(1,0,n-1);
		while(q--)
		{
			char opt[5];
			cin>>opt;
			if(opt[0]=='U')
			{
				int x,y;
				read(x),read(y);
				change(1,x,y);
			}
			else
			{
				int x,y;
				read(x),read(y);
				cout<<query(1,x,y)<<endl;
			}
		}
	}
	return 0;
}

