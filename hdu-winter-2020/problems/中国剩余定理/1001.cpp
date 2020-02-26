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
ll T,a,b,c,d,tim;
ll n[3],m,p[3],t[3],pp[3];
ll ksm(ll a,ll b,ll p)
{
	ll ans=1%p;
	while(b)
	{
		if(b&1) ans=(ans*a)%p;
		a=(a*a)%p;
		b>>=1;
	}
	return ans;
}
int main()
{
	cin>>T;n[0]=23,n[1]=28,n[2]=33;
	m=n[0]*n[1]*n[2];
	pp[0]=21,pp[1]=11;pp[2]=19;
	while(~scanf("%lld%lld%lld%lld",&a,&b,&c,&d))
	{
		if(a==-1&&b==-1&&c==-1&&d==-1) break;
		tim++;
		ll ans=0;
		t[0]=a%n[0],t[1]=b%n[1],t[2]=c%n[2];
		for(int i=0;i<3;i++) p[i]=m/n[i];
		for(int i=0;i<3;i++)
		{
			ll inv=ksm(p[i],pp[i],n[i]);
			ans=(ans+inv*p[i]*t[i])%m;
		}
		ans=ans-d;
		if(ans<=0) ans+=m;
		cout<<"Case "<<tim<<": the next triple peak occurs in "<<ans<<" days."<<endl;
	}
	return 0;
}
