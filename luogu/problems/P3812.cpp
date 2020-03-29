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
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
template<class T>inline void rd(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=60;
ll a[maxn],b[maxn],n;
int main()
{
	cin>>n;
	rep(i,1,n)
	{
		rd(a[i]);
		dep(j,50,0)
		{
			if(a[i]>>j&1)
			{
				if(b[j]) a[i]^=b[j];
				else
				{
					b[j]=a[i];
					rep(k,0,j-1) if(b[j]>>k&1) b[j]^=b[k];
					rep(k,j+1,50) if(b[k]>>j&1) b[k]^=b[j];
					break;
				}
			}
		}
	}
	ll ans=0;
	rep(i,0,50) ans^=b[i];
	cout<<ans<<endl;
	return 0;
}
