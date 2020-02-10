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
int n;
int f1[maxn],f2[maxn],a[maxn];
int ans=0;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) read(a[i]);
	f1[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]>a[i-1]) f1[i]=f1[i-1]+1;
		else f1[i]=1;
	}
	f2[n]=1;
	for(int i=n-1;i>=1;i--)
	{
		if(a[i]<a[i+1]) f2[i]=f2[i+1]+1;
		else f2[i]=1;
	}
	for(int i=1;i<=n;i++) ans=max(ans,max(f1[i],f2[i]));
	for(int i=2;i<=n-1;i++)
	{
		if(a[i-1]<a[i+1]) ans=max(ans,f1[i-1]+f2[i+1]);
	}
	cout<<ans<<endl;
	return 0;
}

