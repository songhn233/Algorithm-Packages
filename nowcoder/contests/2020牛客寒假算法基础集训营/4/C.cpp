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
const int maxn=200050;
const ll p=998244353;
ll n,k;
ll a[maxn],vis[maxn];
ll ksm(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=(res*a)%p;
		a=(a*a)%p;
		b>>=1;
	}
	return res;
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) 
	{
		read(a[i]);
		if(a[i]==0)
		{
			a[i]=1;
			vis[i]=1;
		}
	}
	ll temp=1;
	int flag=0;
	for(int i=1;i<=k;i++) 
	{
		temp=(temp*a[i])%p;
		if(vis[i]) flag++;
	}
	ll ans=temp,t=1;
	if(flag) ans=0;
	for(int i=k+1;i<=n;i++)
	{
		temp=(temp*ksm(a[t],p-2))%p;
		temp=(temp*a[i])%p;
		if(vis[i]) flag++;
		if(vis[t]) flag--;
		t++;
		if(!flag) ans=max(ans,temp);
	}
	cout<<ans<<endl;
	return 0;
}

