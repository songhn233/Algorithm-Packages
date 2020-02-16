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
ll T,n,m;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		if(m==0)
		{
			puts("0");
			continue;
		}
		else
		{
			ll ans=n*(n+1)/2;
			ans-=n-m;
			ll temp=n/2;
			if(m>=temp) cout<<ans<<endl;
			else
			{
				ll ans=n*(n+1)/2;
				n=n-m;
				ll temp=n/(m+1);
				ll tt=n%(m+1);
				cout<<ans-tt*(temp+1)*(temp+2)/2-(m+1-tt)*(temp+1)*temp/2<<endl;
			}
		}
	}
	return 0;
}
