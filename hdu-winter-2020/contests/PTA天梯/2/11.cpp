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
const int maxn=10050;
int n,k,m;
double ans[maxn];
int main()
{
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++)
	{
		int maxx=-inf,minx=inf;
		int x;
		double temp=0;
		for(int j=1;j<=k;j++)
		{
			read(x);
			maxx=max(maxx,x);
			minx=min(minx,x);
			temp+=x;
		}
		temp-=(maxx+minx);
		temp/=(k-2);
		ans[i]=temp;
	}
	sort(ans+1,ans+n+1);
	for(int i=n-m+1;i<=n;i++) 
	{
		if(i!=n) printf("%.3lf ",ans[i]);
		else printf("%.3lf\n",ans[i]);
	}
	return 0;
}

