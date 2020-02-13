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
const int maxn=500050;
int n;
ll a[maxn],l[maxn],r[maxn],c[maxn];
ll sum[maxn],cnt[maxn];
ll lowbit(ll x){return x&-x;}
void add(int x,int p)
{
	while(x<=n)
	{
		c[x]+=p;
		x+=lowbit(x);
	}
}
ll query(int x)
{
	ll res=0;
	while(x)
	{
		res+=c[x];
		x-=lowbit(x);
	}
	return res;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		read(a[i]),read(l[i]),read(r[i]);
		sum[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		sum[a[i]]--;
		add(a[i],-cnt[a[i]]);
		cout<<query(r[i])-query(l[i]-1)<<" ";
		cnt[a[i]]++;
		add(a[i],sum[a[i]]);
	}
	cout<<endl;
	return 0;
}

