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
const int maxn=25;
ll T,n,m,M;
ll a[maxn],b[maxn],p[maxn];
void exgcd(ll &x,ll &y,ll a,ll b)
{
	if(b==0)
	{
		x=1,y=0;
		return;
	}
	else
	{
		ll temp=x;
		x=y;
		y=temp-(a/b)*y;
	}
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		M=1;
		for(int i=1;i<=m;i++) cin>>a[i],M*=a[i];
		for(int i=1;i<=m;i++) cin>>b[i];
		for(int i=1;i<=m;i++) p[i]=M/a[i];
		ll ans=0;
		ll x,y;
		for(int i=1;i<=m;i++)
		{
			exgcd(x,y,p[i],a[i]);
			ll inv=(x%a[i]+a[i])%a[i];
			cout<<(inv*p[i])%a[i]<<"--"<<endl; 
			ans=(ans+inv*p[i]*b[i])%M;
		}
		if(ans>n) puts("0");
		else cout<<(n-ans)/M+1<<endl;
	}
	return 0;
}
