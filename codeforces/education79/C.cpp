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
const int maxn=100050;
int T,n,m;
int a[maxn],b[maxn],c[maxn];
map<int,int> mp;
int main()
{
	cin>>T;
	while(T--)
	{
		mp.clear();
		read(n),read(m);
		ll ans=0;
		for(int i=0;i<=n;i++) c[i]=0;
		for(int i=1;i<=n;i++) 
		{
			read(a[i]);
			mp[a[i]]=i;
		}
		for(int i=1;i<=m;i++) 
		{
			read(b[i]);
			c[mp[b[i]]]=1;
		}
		for(int i=1;i<=n;i++) c[i]+=c[i-1];
		ll maxx=0,p=0;
		for(int i=1;i<=m;i++)
		{
			ll temp=mp[b[i]];
			if(temp<=maxx)
			{
				ans++;
				p++;
				continue;
			}
			maxx=max(maxx,temp);
			ans+=2*(temp-p)-1;
			p++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

