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
const int maxn=2050;
ll n,m;
ll a[maxn],b[maxn];
map<int,int> mp,pan;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) read(a[i]),pan[a[i]]++;
	for(int i=1;i<=n;i++) read(b[i]),mp[b[i]]++;
	if(pan==mp) puts("0");
	else
	{
		ll ans=inf;
		for(int i=1;i<=n;i++)
		{
			ll temp;
			pan.clear();
			if(b[i]>a[1]) temp=b[i]-a[1];
			else temp=b[i]-a[1]+m;
			//cout<<temp<<"--"<<endl;
			for(int j=1;j<=n;j++)
			{
				pan[(a[j]+temp)%m]++;
			}
			if(pan==mp) ans=min(ans,temp);
		}
		cout<<ans<<endl;
	}
	return 0;
}

