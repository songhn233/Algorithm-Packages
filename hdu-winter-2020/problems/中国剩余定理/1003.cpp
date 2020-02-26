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
ll n,a,m,b[150];
ll gcd(int a,int b){return b?gcd(b,a%b):a;}
int main()
{
	while(~scanf("%lld%lld",&n,&a))
	{
		if(n==0&&a==0) break;
		for(int i=1;i<=n;i++) cin>>b[i];
		ll ans=b[1];
		for(int i=2;i<=n;i++) ans=(ans/gcd(ans,b[i]))*b[i];
		cout<<ans-a<<endl;
	}
	return 0;
}
