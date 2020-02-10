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
const int maxn=300050;
ll f[maxn];
ll n,a,b,c;
string s,t;
int main()
{
	cin>>n>>a>>b>>c;
	s=" ";
	cin>>t;
	s+=t;
	for(int i=1;i<=n;i++)
	{
		f[i]=max(f[i],f[i-1]);
		if(i>=4)
		{
			if(s.substr(i-3,4)=="nico")
				f[i]=max(f[i],f[i-4]+a);
		}
		if(i>=6)
		{
			if(s.substr(i-5,6)=="niconi")
				f[i]=max(f[i],f[i-6]+b);
		}
		if(i>=10)
		{
			if(s.substr(i-9,10)=="niconiconi")
			{
				f[i]=max(f[i],f[i-10]+c);
			}
				
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,f[i]);
	cout<<ans<<endl;
	return 0;
}

