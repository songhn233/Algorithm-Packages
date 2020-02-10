#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
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
const ll mod=1e9+7;
const int maxn=100050;
string s;
ll f[maxn];
void init()
{
	f[0]=f[1]=1;
	for(int i=2;i<=100000;i++)
		f[i]=(f[i-1]+f[i-2])%mod;
}
int main()
{
	init();
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='m'||s[i]=='w')
		{
			puts("0");
			return 0;
		}
	}
	ll ans=1,temp=0;
	for(int i=1;i<s.size();i++)
	{
		if(s[i]=='u'&&s[i-1]=='u') temp++;
		else if(s[i]=='n'&&s[i-1]=='n') temp++;
		else if(temp) ans=ans*f[temp+1]%mod,temp=0;	
	}
	if(temp) ans=ans*f[temp+1]%mod;
	cout<<ans<<endl;
	return 0;
}

