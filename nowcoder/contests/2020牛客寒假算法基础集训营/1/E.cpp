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
ll n,ans;
int main()
{
	cin>>n;
	while(n!=2)
	{
		ans++;
		ll temp=0;
		for(ll i=1;i<=n/i;i++)
		{
			if(n%i==0)
			{
				if(i*i!=n) temp+=2;
				else temp++;
			}	
		}
		n=temp;
	}
	cout<<ans<<endl;
	return 0;
}

