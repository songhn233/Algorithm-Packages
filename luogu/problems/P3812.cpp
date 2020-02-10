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
const int maxn=60;
ll n,p[maxn];
void add(ll x)
{
	for(ll i=50;i>=0;i--)
	{
		if(x>>i&1)
		{
			if(!p[i])
			{
				p[i]=x;
				break;
			}
			else x^=p[i];
		}
	}
}
ll query()
{
	ll res=0;
	for(ll i=50;i>=0;i--)
	{
		if((res^p[i])>res) res^=p[i];
	}
	return res;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		ll x;cin>>x;
		add(x);
	}
	cout<<query()<<endl;
	return 0;
}


