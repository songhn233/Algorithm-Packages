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
int n;
map<int,int> mp;
int main()
{
	cin>>n;
	int pos=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		int k;read(k);
		for(int j=1;j<=k;j++)
		{
			int x;read(x);
			mp[x]++;
			if(mp[x]>ans)
			{
				ans=mp[x];
				pos=x;
			}
			else if(mp[x]==ans)
			{
				if(x>pos) pos=x;
			}
		}
	}
	cout<<pos<<" "<<ans<<endl;
	return 0;
}
