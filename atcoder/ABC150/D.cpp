#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define ll unsigned long long
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
const int maxn=100050;
ll n,m;
ll a[maxn];
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) read(a[i]),a[i]/=2;
	int t=0;
	while(a[1]%2==0) a[1]/=2,t++;
	for(int i=2;i<=n;i++)
	{
		if((a[i]%(1<<t))!=0)
		{
			puts("0");
			return 0;
		}
		a[i]/=(1<<t);
		if(a[i]%2==0)
		{
			puts("0");
			return 0;
		}
	}
	m/=(1<<t);
	ll res=a[1];
	for(int i=2;i<=n;i++)
	{
		ll temp=gcd(res,a[i]);
		res=(res*a[i])/temp;
	}
	ll ans=m/res;
	cout<<(ans+1)/2<<endl;
	return 0;
}
