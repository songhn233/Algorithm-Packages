#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
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
const int maxn=150;
int T,n;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			int x;read(x);
			sum+=x;
		}
		int ans=(sum+n-1)/n;
		cout<<ans<<endl;
	}
	return 0;
}


