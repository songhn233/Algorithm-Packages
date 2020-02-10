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
int T,n; 
int main()
{
	cin>>T;
	while(T--)
	{
		read(n);
		int ans1=inf,ans2=0;
		for(int i=1;i<=n;i++)
		{
			int x,y;read(x),read(y);
			ans1=min(ans1,y);
			ans2=max(ans2,x);
		}
		if(ans2<=ans1) puts("0");
		else cout<<ans2-ans1<<endl;
	}
	return 0;
}

