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
const int maxn=5050;
int n;
PII a[maxn];
double calc(int t1,int t2,int t3)
{
	int x1=a[t1].first,y1=a[t1].second;
	int x2=a[t2].first,y2=a[t2].second;
	int x3=a[t3].first,y3=a[t3].second;
	double res=fabs(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2)*0.5;
	return res;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		read(x),read(y);
		a[i]=make_pair(x,y);
	}
	double ans=inf;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				ans=min(ans,calc(i,j,k));
			}
		}
	}
	printf("%.3lf\n",ans);
	return 0;
}
