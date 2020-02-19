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
const int maxn=100050;
int T,n,x,a[maxn];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>x;
		int maxx=0,pan=0;
		for(int i=1;i<=n;i++) 
		{
			read(a[i]),maxx=max(maxx,a[i]);
			if(a[i]==x) pan=1;
		}
		if(pan) puts("1");
		else
		{
			if(x%maxx==0)
			{
				int ans=x/maxx;
				cout<<ans<<endl;
			}
			else
			{
				if(maxx>x) puts("2");
				else
				{
					int ans=(x/maxx)+1;
					cout<<ans<<endl;
				}
			}
		}
		
		
	}
	return 0;
}

