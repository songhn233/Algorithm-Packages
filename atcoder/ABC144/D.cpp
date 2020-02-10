#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const long double pi=acos(-1);
const long double eps=1e-12;
double a,b,x;
bool calc(long double mid)
{
	long double res=0.0;
	if(tan(mid)>b/a) res=a*b*b/(2*tan(mid));
	else res=a*a*b-a*a*a*tan(mid)/2;
	
	return (res-x>eps);
}
int main()
{
	cin>>a>>b>>x;
	long double l=0.0,r=pi/2;
	while(r-l>eps)
	{
		long double mid=(l+r)/2;
		if(calc(mid)) l=mid;
		else r=mid;
	}
	printf("%.10Lf\n",(l/pi)*180);
	return 0;
}
