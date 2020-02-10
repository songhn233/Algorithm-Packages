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
int n;
ll a,b,sa,sb;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int main()
{
	cin>>n;
	scanf("%lld/%lld",&sa,&sb);
	for(int i=2;i<=n;i++)
	{
		scanf("%lld/%lld",&a,&b);
		if(a<0)
		{
			a=-a;
			sa=sa*b-a*sb;
			sb=sb*b;
			
			ll t=gcd(abs(sa),sb);
			sa/=t;
			sb/=t;
		}
		else
		{
			sa=sa*b+a*sb;
			sb=sb*b;
			ll t=gcd(abs(sa),sb);
			sa/=t;
			sb/=t;
		}
	}
	if(sa==0) puts("0");
	else if(sb==1) printf("%lld\n",sa);
	else 
	{
		ll t=sa/sb;
		if(t>0) printf("%lld %lld/%lld\n",t,sa%sb,sb);
		else printf("%lld/%lld\n",sa,sb);
	}
	return 0;
}

