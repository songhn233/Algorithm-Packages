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
int n,m;
char s[maxn];
map<char,bool> mp;
int main()
{
	cin>>n>>m;
	cin>>(s+1);
	for(int i=1;i<=m;i++)
	{
		char x;cin>>x;
		mp[x]=true;
	}
	int last=0;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(mp[s[i]]) ans+=i-last;
		else last=i;
	}
	cout<<ans<<endl;
	return 0;
}

