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
const int maxn=50050;
int n,m;
struct tree{
	int l,r;
	int lmax,rmax,maxx;
	int tag;
}t[maxn<<2];
void pushup(int id)
{
	t[id].maxx=max(t[ls].maxx,t[rs].maxx);
	t[id].maxx=max(t[id].maxx,t[ls].rmax+t[rs].lmax);
	t[id].lmax=t[ls].lmax;t[id].rmax=t[rs].rmax;
	if(t[ls].lmax==t[ls].r-t[ls].l+1)
		t[id].lmax=max(t[id].lmax,t[ls].r-t[ls].l+1+t[rs].lmax);
	if(t[rs].rmax==t[rs].r-t[rs].l+1)
		t[id].rmax=max(t[id].rmax,t[rs].r-t[rs].l+1+t[ls].rmax);
	//cout<<t[ls].rmax<<"   "<<t[id].l<<"   "<<t[id].r<<"-----"<<endl;
}
void pushdown(int id)
{
	if(t[id].tag)
	{
		if(t[id].tag==-1)
		{
			t[ls].tag=-1;t[rs].tag=-1;
			t[ls].lmax=t[ls].rmax=t[ls].maxx=t[ls].r-t[ls].l+1;
			t[rs].lmax=t[rs].rmax=t[rs].maxx=t[rs].r-t[rs].l+1;
		}
		if(t[id].tag==1)
		{
			t[ls].tag=1;t[rs].tag=1;
			t[ls].lmax=t[ls].rmax=t[ls].maxx=0;
			t[rs].lmax=t[rs].rmax=t[rs].maxx=0;
		}
		t[id].tag=0;
	}
}
void build(int id,int l,int r)
{
	t[id].tag=0;t[id].l=l;t[id].r=r;
	if(l==r)
	{
		t[id].lmax=t[id].rmax=t[id].maxx=1;
		return ;
	}
	int mid=l+r>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(id);
}
int query(int id,int x)
{
	if(t[id].l==t[id].r) return t[id].l;
	pushdown(id);
	int mid=t[id].l+t[id].r>>1;
	if(t[ls].maxx>=x) return query(ls,x);
	else if(t[ls].rmax+t[rs].lmax>=x) return mid-t[ls].rmax+1;
	else return query(rs,x);
}
void change(int id,int l,int r,int p)
{
	if(t[id].l>=l&&t[id].r<=r)
	{
		if(p==1)
		{
			t[id].lmax=t[id].rmax=t[id].maxx=0;
			t[id].tag=1;
		}
		else
		{
			t[id].lmax=t[id].rmax=t[id].maxx=t[id].r-t[id].l+1;
			t[id].tag=-1;
		}
		return ;
	}
	pushdown(id);
	int mid=t[id].l+t[id].r>>1;
	if(l<=mid) change(ls,l,r,p);
	if(r>mid) change(rs,l,r,p);
	pushup(id);
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		build(1,1,n);
		while(m--)
		{
			int opt;cin>>opt;
			if(opt==1)
			{
				int x;read(x);
				if(t[1].maxx>=x)
				{
					int ans=query(1,x);
					cout<<ans<<endl;
					change(1,ans,ans+x-1,1);
				}
				else puts("0");
			}
			else
			{
				int x,y;read(x),read(y);
				change(1,x,x+y-1,-1);
			}
		}
	}
	return 0;
}

