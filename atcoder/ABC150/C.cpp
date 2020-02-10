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
const int maxn=15;
int n,a[maxn],b[maxn],fac[maxn];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	fac[0]=1;
	for(int i=1;i<=8;i++) fac[i]=fac[i-1]*i;
	int ans1=0,ans2=0;
	for(int i=1;i<=n-1;i++)
	{
		int cnt=0;
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]<a[i]) cnt++;
		}
		ans1+=cnt*fac[n-i];
	}
	
	for(int i=1;i<=n-1;i++)
	{
		int cnt=0;
		for(int j=i+1;j<=n;j++)
		{
			if(b[j]<b[i]) cnt++;
		}
		ans2+=cnt*fac[n-i];
	}
	//cout<<ans1<<"  "<<ans2<<endl;
	cout<<abs(ans1-ans2)<<endl;
	return 0;
}

