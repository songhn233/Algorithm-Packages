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
ll T,n,b,g;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>g>>b;
		ll t;
		if((n/2)*2!=n)
		{
			t=(n/2)+1;
		}
		else t=(n/2);
		ll tt,rest,temp;
		temp=n-t;
		if((t/g)*g!=t) 
		{
			tt=(t/g)+1;
			rest=t-(t/g)*g;
		}
		else tt=t/g;
		ll res=(tt-1)*b+t;
		if(b*(tt-1)<temp) res+=temp-b*(tt-1);
		cout<<res<<endl;
	}
	return 0;
}

