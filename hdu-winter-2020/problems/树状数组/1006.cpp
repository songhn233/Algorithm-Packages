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
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=20050;
const int N=20000;
ll n,c1[maxn],c2[maxn];
struct node{
	ll v,x;
	bool operator<(const node&t) const{
		return v<t.v;
	}
}a[maxn];
int lowbit(int x){return x&-x;}
void add1(int x,int p)
{
	while(x<=N)
	{
		c1[x]+=p;
		x+=lowbit(x);
	}
}
void add2(int x,int p)
{
	while(x<=N)
	{
		c2[x]+=p;
		x+=lowbit(x);
	}
}
ll query1(int x)
{
	ll res=0;
	while(x)
	{
		res+=c1[x];
		x-=lowbit(x);
	}
	return res;
}
ll query2(int x)
{
	ll res=0;
	while(x)
	{
		res+=c2[x];
		x-=lowbit(x);
	}
	return res;
}
int main()
{
	cin>>n;
	memset(c1,0,sizeof(c1));
	memset(c2,0,sizeof(c2));
	for(int i=1;i<=n;i++) read(a[i].v),read(a[i].x);
	sort(a+1,a+n+1);
	ll ans=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		ll t=query1(a[i].x);
		ans+=(a[i].x*t-query2(a[i].x))*a[i].v;
		ans+=(sum-query2(a[i].x)-(i-t-1)*a[i].x)*a[i].v;
		sum+=a[i].x;
		add1(a[i].x,1);
		add2(a[i].x,a[i].x);
	}
	cout<<ans<<endl;
	return 0;
}

