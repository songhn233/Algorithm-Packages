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
ll n,m,p;
int main()
{
	read(n),read(m),read(p);
	int t1,t2;
	t1=t2=-1;
	for(int i=0;i<n;i++) 
	{
		ll x;read(x);
		if(x%p&&t1==-1)
		{
			t1=i;
		}
	}
	for(int i=0;i<m;i++) 
	{
		ll x;read(x);
		if(x%p&&t2==-1)
		{
			t2=i;
		}
	}
	cout<<t1+t2<<endl;
	return 0;
}

