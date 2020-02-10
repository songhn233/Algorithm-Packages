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
const int maxn=200050;
ll n,a[maxn];
ll vis[35][2],ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-(a+1);
	for(int i=1;i<=n;i++) 
	{
		for(int j=0;j<=30;j++)
		{
			if((a[i]>>j)&1) vis[j][1]=1;
			else vis[j][0]=1;
		}
	}
	for(int i=0;i<=30;i++)
	{
		if(vis[i][0]&&vis[i][1])
		{
			ans=(1ll<<i)*(n-1);
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}

