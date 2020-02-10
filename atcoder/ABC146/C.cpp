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
const int N=1000000000;
ll a,b,x;
int main()
{
	cin>>a>>b>>x;
	ll ans=0;
	for(int i=1;i<=9;i++)
	{
		ll temp=x-b*i;
		if(temp<=0) break;
		ll t=temp/a;
		if(t>=(ll)pow(10,i)) t=pow(10,i)-1;
		ans=max(ans,t);
	}
	if(a*N+b*10<=x) ans=N;
	cout<<ans<<endl;
	return 0;
}

