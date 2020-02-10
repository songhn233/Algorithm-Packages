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
int T,a,b;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>a>>b;
		if(a>b) swap(a,b);
		if(a==b) puts("0");
		else
		{
			int i=1,ans=0;
			while(a<b)
			{
				a+=i;
				i++;
				ans++;
			}
			if(a==b) cout<<ans<<endl;
			else if((a-b)%2==0) cout<<ans<<endl;
			else
			{
				if(i%2==0) cout<<ans+2<<endl;
				else cout<<ans+1<<endl;
			}
		}
	}
	return 0;
}

