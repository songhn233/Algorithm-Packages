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
const int maxn=1000010;
int n;
string s;
struct tree{
	int l,r;
	int minx,maxx,tag;
}t[maxn<<2];
void build(int id,int l,int r)
{
	t[id].minx=t[id].tag=0;
	t[id].l=l,t[id].r=r;
	if(l==r) return ;
	int mid=l+r>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
}
void pushdown(int id)
{
	if(t[id].tag)
	{
		t[ls].maxx+=t[id].tag;t[ls].minx+=t[id].tag;
		t[rs].maxx+=t[id].tag;t[rs].minx+=t[id].tag;
		t[ls].tag+=t[id].tag;t[rs].tag+=t[id].tag;
		t[id].tag=0;
	}
	return ;
}
void change(int id,int l,int r,int p)
{
	if(l<=t[id].l&&r>=t[id].r)
	{
		t[id].minx+=p;
		t[id].maxx+=p;
		t[id].tag+=p;
		return ;
	}
	pushdown(id);
	int mid=t[id].l+t[id].r>>1;
	if(l<=mid) change(ls,l,r,p);
	if(r>mid) change(rs,l,r,p);
	t[id].maxx=max(t[ls].maxx,t[rs].maxx);
	t[id].minx=min(t[ls].minx,t[rs].minx);
}
int query_min(int id,int l,int r)
{
	if(l<=t[id].l&&r>=t[id].r) return t[id].minx;
	pushdown(id);
	int mid=t[id].l+t[id].r>>1;
	int res=inf;
	if(l<=mid) res=min(res,query_min(ls,l,r));
	if(r>mid) res=min(res,query_min(rs,l,r));
	return res;
}
int query_max(int id,int l,int r)
{
	if(l<=t[id].l&&r>=t[id].r) return t[id].maxx;
	pushdown(id);
	int mid=t[id].l+t[id].r>>1;
	int res=-inf;
	if(l<=mid) res=max(res,query_max(ls,l,r));
	if(r>mid) res=max(res,query_max(rs,l,r));
	return res;
}
int main()
{
	cin>>n;
	cin>>s;
	string ss(n+1,' ');
	int pos=1;
	build(1,1,n);
	int cnt=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='R') pos++;
		else if(s[i]=='L') pos=max(pos-1,1);
		else
		{
			if(ss[pos]=='(') change(1,pos,n,-1),cnt--;
			else if(ss[pos]==')') change(1,pos,n,1),cnt++;
			
			ss[pos]=s[i];
			if(ss[pos]=='(') change(1,pos,n,1),cnt++;
			else if(ss[pos]==')') change(1,pos,n,-1),cnt--;
		}
		if(cnt!=0||t[1].minx) printf("-1 ");
		else printf("%d ",t[1].maxx);
	}
	puts("");
	return 0;
}

