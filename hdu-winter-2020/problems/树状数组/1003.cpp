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
const int maxn=1000050;
int n,a[maxn],c[maxn],mp[maxn],num;
int lowbit(int x){return x&-x;}
void add(int x,int p)
{
	while(x<=n)
	{
		c[x]+=p;
		x+=lowbit(x);
	}
}
int query(int x)
{
	int res=0;
	while(x)
	{
		res+=c[x];
		x-=lowbit(x);
	}
	return res;
}
int main()
{
	while(~scanf("%d",&n))
	{
		memset(c,0,sizeof(c));
		num=0;
		for(int i=1;i<=n;i++) 
		{
			read(a[i]);
			mp[++num]=a[i];
		}
		sort(mp+1,mp+num+1);
		num=unique(mp+1,mp+num+1)-mp-1;
		ll ans=0;
		for(int i=n;i>=1;i--)
		{
			int x=lower_bound(mp+1,mp+num+1,a[i])-mp;
			ans+=query(x);
			add(x,1);
		}
		cout<<ans<<endl;
	}
	return 0;
}

