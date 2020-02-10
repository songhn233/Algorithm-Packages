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
int n,c[maxn]; 
int main()
{
	while(~scanf("%d",&n))
	{
		if(n==0) break;
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++)
		{
			int x,y;read(x),read(y);
			c[x]++,c[y+1]--;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=c[i];
			if(i!=n) cout<<ans<<" ";
			else cout<<ans<<endl;
		}
	}
	return 0;
}

