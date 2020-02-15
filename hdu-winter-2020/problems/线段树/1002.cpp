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
const int maxn=200050;
int n,m,a[maxn];
struct tree{
	int id,l,r;
	int maxx;
}t[maxn<<2];
void build(int id,int l,int r)
{
	t[id].l=l,t[id].r=r;
	if(l==r)
	{
		t[id].maxx=a[l];
		return ;
	}
	int mid=l+r>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[id].maxx=max(t[ls].maxx,t[rs].maxx);
}
void change(int id,int x,int p)
{
	if(t[id].l==t[id].r)
	{
		t[id].maxx=p;
		return ;
	}
	int mid=t[id].l+t[id].r>>1;
	if(x<=mid) change(ls,x,p);
	else change(rs,x,p);
	t[id].maxx=max(t[ls].maxx,t[rs].maxx);
}
int query(int id,int l,int r)
{
	if(t[id].l>=l&&t[id].r<=r)
	{
		return t[id].maxx;
	}
	int mid=t[id].l+t[id].r>>1;
	int res=-inf;
	if(l<=mid) res=max(res,query(ls,l,r));
	if(r>mid) res=max(res,query(rs,l,r));
	return res;
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=1;i<=n;i++) read(a[i]);
		build(1,1,n);
		while(m--)
		{
			char opt[5];
			int x,y;
			cin>>opt;
			if(opt[0]=='Q')
			{
				read(x),read(y);
				cout<<query(1,x,y)<<endl;
			}
			else
			{
				read(x),read(y);
				change(1,x,y);
			}
		}
	}
	return 0;
}

