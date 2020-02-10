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
int n,a,b;
double x;
double f[1050];
int main()
{
	cin>>n>>x>>a>>b;
	x=0.01*x;
	for(int i=1;i<=n;i++)
	{
		f[i]=x*(f[i-1]+a)+(1-x)*(f[i-1]+b);
	}
	printf("%.2lf\n",f[n]);
	return 0;
}

