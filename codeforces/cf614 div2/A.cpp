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
int T;
int n,s,k;
map<int,int> mp;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>s>>k;
		mp.clear();
		int ans=inf;
		for(int i=1;i<=k;i++)
		{
			int x;read(x);
			mp[x]=1;
		}
		for(int i=s;i<=n;i++)
		{
			if(mp[i]==0) 
			{
				ans=i-s;
				break;
			}
		}
		for(int i=s;i>=1;i--)
		{
			if(mp[i]==0) 
			{
				ans=min(ans,abs(i-s));
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
