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
const int maxn=300050;
ll n,c[maxn],s[maxn],ans[maxn];
bool calc(int x,int k)
{
	if(s[x]>=x*k) return true;
	return false;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		c[x]++;
		s[c[x]]++;
	}
	for(int i=1;i<=n;i++) s[i]+=s[i-1];
	int t=n;
	for(int i=1;i<=n;i++)
	{
		while(t&&(!calc(t,i))) t--;
		ans[i]=t;
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
	return 0;
}
