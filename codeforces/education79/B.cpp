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
int T;
ll n,s;
ll a[maxn];
int main()
{
	cin>>T;
	while(T--)
	{
		read(n),read(s);
		for(int i=1;i<=n;i++) read(a[i]);
		int temp=0,ans=0;
		ll sum=0;
		int maxx=0;
		for(int i=1;i<=n;i++)
		{
			sum+=a[i];
			if(maxx<a[i])
			{
				maxx=a[i];
				temp=i;
			}
			if(sum>s) 
			{
				if(sum-maxx<=s) ans=temp;
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

