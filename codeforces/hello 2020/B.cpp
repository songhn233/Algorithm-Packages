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
const int maxn=1000050;
int n,m,num;
int a[maxn],s[maxn],flag[maxn];
int main()
{
	cin>>n;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		int x;read(x);
		int minx=inf,maxx=0,pan=0;
		for(int j=1;j<=x;j++)
		{
			int t;read(t);
			maxx=max(maxx,t);
			minx=min(minx,t);
			if(t>minx) pan=1;
			m=max(m,t);
		}
		if(pan) flag[i]=1,num++;
		else
		{
			a[i]=minx;
			s[maxx]++;
		}
	}
	for(int i=m+1;i>=0;i--) s[i]+=s[i+1];
	for(int i=1;i<=n;i++)
	{
		if(flag[i]) ans+=n;
		else
		{
			ans+=s[a[i]+1];
			ans+=num;
		}
	}
	cout<<ans<<endl;
	return 0;
}

