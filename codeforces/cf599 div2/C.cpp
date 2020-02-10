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
ll n;
vector<ll> a;
int main()
{
	cin>>n;
	ll cnt=0,ans=0;
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			while(n%i==0) n/=i;
			cnt++;ans=i;
		}
	}
	if(cnt==0) cout<<n<<endl;
	else if(n==1&&cnt==1) cout<<ans<<endl;
	else cout<<1<<endl;
	return 0;
}

