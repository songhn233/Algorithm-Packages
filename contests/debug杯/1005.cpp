#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define INF ~(1<<31)
#define def 100010
using namespace std;

ll a[def],b[def];

int main()
{	long _=1,__=1,n,m,i,now;
	ll ans;
	for(((1)?scanf("%ld",&_):EOF);_;_--,__++){
		scanf("%ld%ld",&n,&m);
		for(i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(i=1;i<=n;i++)
			scanf("%lld",&b[i]);
		now=m;
		ans=0;
		for(i=1;i<=n;i++)if(b[i]){
			if(now>b[i]&&i!=n)
				now-=b[i];
			else{
				b[i]=max(0,b[i]-now);
				ans+=2*a[i]*(b[i]/m+1);
				now=m-b[i]%m;
				if(i==n&&now<m)
					ans+=2*a[i];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}