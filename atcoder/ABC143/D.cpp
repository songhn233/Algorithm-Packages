#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=2050;
int n,a[maxn];
int main()
{
	read(n);
	F(i,1,n) read(a[i]);
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i+1;j<=n-1;j++)
		{
			int l=j,r=n;
			while(l<r)
			{
				int mid=l+r+1>>1;
				if(a[mid]<a[i]+a[j]) l=mid;
				else r=mid-1;
			}
			if(l==j) continue;
			ans+=l-j;
		}
	}
	cout<<ans<<endl;
	return 0;
}


