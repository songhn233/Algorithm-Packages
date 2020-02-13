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
const int maxn=1050;
ll T,a[maxn];
ll n,m;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		memset(a,0,sizeof(a));
		ll sum=0,res=0;
		for(int i=1;i<=m;i++)
		{
			ll x;read(x);
			for(ll i=0;i<=60;i++)
			{
				if((x>>i)&1)
				{
					a[i]++;
					break;
				}
			}
			sum+=x;
		}
		if(sum<n)
		{
			puts("-1");
			continue;
		}
		for(ll i=0;i<=60;i++)
		{
			if((n>>i)&1)
			{
				if(!a[i])
				{
					for(ll j=i+1;j<=60;j++)
					{
						if(a[j])
						{
							a[j]--;
							int temp=j;
							while(temp!=i)
							{
								res++;
								temp-=1;
								a[temp]++;
							}
							a[i]++;
							break;
						}
					}
				}
				a[i]--;
			}
			a[i+1]+=a[i]/2;
		}
		cout<<res<<endl;
	}
	return 0;
}
