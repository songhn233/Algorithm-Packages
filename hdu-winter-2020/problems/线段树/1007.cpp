#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ls id<<1
#define rs id<<1|1
using namespace std;
const int maxn=200050;
int n,m,T;
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
struct tree{
	int l,r,co,tag;
}t[maxn<<2];
void build(int id,int l,int r)
{
	t[id].l=l,t[id].r=r,t[id].tag=0;
	if(l==r)
	{
		t[id].co=1;
		return ;
	}
	int mid=l+r>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[id].co=t[ls].co|t[rs].co;
}
void pushdown(int id)
{
	if(t[id].tag)
	{
		t[ls].co=t[id].tag;
		t[rs].co=t[id].tag;
		t[ls].tag=t[id].tag;
		t[rs].tag=t[id].tag;
		t[id].tag=0;
	}
}
void change(int id,int l,int r,int p)
{
	if(l<=t[id].l&&r>=t[id].r)
	{
		t[id].co=1<<(p-1);
		t[id].tag=1<<(p-1);
		return ;
	}
	pushdown(id);
	int mid=t[id].l+t[id].r>>1;
	if(l<=mid) change(ls,l,r,p);
	if(r>mid) change(rs,l,r,p);
	t[id].co=t[ls].co|t[rs].co;
}
int query(int id,int l,int r)
{
	if(l<=t[id].l&&r>=t[id].r)
	{
		return t[id].co;
	}
	pushdown(id);
	int res=0;
	int mid=t[id].l+t[id].r>>1;
	if(l<=mid) res|=query(ls,l,r);
	if(r>mid) res|=query(rs,l,r);
	return res;
}
int main()
{	
	while(scanf("%d%d%d",&n,&m,&T)!=EOF)
    {
		build(1,1,n);
		while(T--)
		{
			char opt[2];
			cin>>opt;
			if(opt[0]=='C')
			{
				int x,y,z;
				x=read(),y=read(),z=read();
				if(x>y) swap(x,y);
				change(1,x,y,z);
			}
			else
			{
				int x,y;
				x=read(),y=read();
				if(x>y) swap(x,y);
				int temp=query(1,x,y);
				int ans=0;
				while(temp)
				{
					if(temp&1) ans++;
					temp>>=1;
				}
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
