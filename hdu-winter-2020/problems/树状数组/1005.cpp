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
const int maxn=50000;
const int N=32001;
int n,c[maxn],ans[maxn];
struct node{
	int x,y;
	bool operator<(const node&t) const{
		if(y==t.y) return x<t.x;
		return y<t.y;
	}
}a[maxn];
int lowbit(int x){return x&-x;}
void add(int x,int p)
{
	while(x<=N)
	{
		c[x]+=p;
		x+=lowbit(x);
	}
}
int query(int x)
{
	int res=0;
	while(x)
	{
		res+=c[x];
		x-=lowbit(x);
	}
	return res;
}
int main()
{
	while(~scanf("%d",&n))
	{
		memset(c,0,sizeof(c));
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;i++) read(a[i].x),read(a[i].y);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			int t=query(a[i].x+1);
			ans[t]++;
			add(a[i].x+1,1);
		}
		for(int i=0;i<n;i++) cout<<ans[i]<<endl;
	}
	return 0;
}

