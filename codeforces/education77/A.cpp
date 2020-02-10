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
int n;
int c[maxn],s[maxn];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i]>>s[i];
		int temp=s[i]/c[i];
		ll ans=0;
		for(int j=1;j<=c[i];j++) ans+=temp*temp;
		int t=s[i]-temp*c[i];
		ans+=(1+2*temp)*t;
		cout<<ans<<endl;
	}
	return 0;
}
