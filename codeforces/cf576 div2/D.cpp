#include<cstdio>
#include<algorithm>
#include<iostream>
#define ls id<<1
#define rs id<<1|1
using namespace std;
const int maxn=200010;
int n,q,a[maxn];
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
struct node{
	int l,r;
	int min,tag;
}t[maxn<<2];
void build(int id,int l,int r)
{
	t[id].l=l,t[id].r=r,t[id].tag=0;
	if(l==r)
	{
		t[id].min=a[l];
		return ;
	}
	int mid=l+r>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[id].min=min(t[ls].min,t[rs].min);
}
void pushdown(int id)
{
	if(t[id].tag)
	{
		t[ls].tag=max(t[ls].tag,t[id].tag);
		t[rs].tag=max(t[rs].tag,t[id].tag);
		t[ls].min=max(t[ls].min,t[id].tag);
		t[rs].min=max(t[rs].min,t[id].tag);
		t[id].tag=0;
	}
}
void change(int id,int p,int x)
{
	if(t[id].l==t[id].r) 
	{
		t[id].min=x;
		return ;
	}
	pushdown(id);
	int mid=t[id].l+t[id].r>>1;
	if(p<=mid) change(ls,p,x);
	else change(rs,p,x);
	t[id].min=min(t[ls].min,t[rs].min);
}
void update(int id,int x)
{
	if(x<=t[id].min) return ;
	t[id].min=x;
	t[id].tag=max(t[id].tag,x);
}
int query(int id,int p)
{
	if(t[id].l==t[id].r) return t[id].min;
	pushdown(id);
	int mid=t[id].l+t[id].r>>1;
	if(p<=mid) query(ls,p);
	else query(rs,p);
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	build(1,1,n);
	q=read();
	while(q--)
	{
		int opt,p,x;
		opt=read();
		if(opt==1)
		{
			p=read(),x=read();
			change(1,p,x);
		}
		else
		{
			x=read();
			update(1,x);
		}
	}
	for(int i=1;i<=n;i++) printf("%d ",query(1,i));
	return 0;
}
