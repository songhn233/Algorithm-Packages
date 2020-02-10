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
const double eps=1e-6;
int T;
double y;
double calc(double x)
{
	return 6*pow(x,7)+8*pow(x,6)+7*pow(x,3)+5*x*x-y*x;
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>y;
		double l=0,r=100;
		while(r-l>eps)
		{
			double lmid=(1.0/3.0)*(r-l)+l;
			double rmid=(2.0/3.0)*(r-l)+l;
			if(calc(lmid)>calc(rmid)) l=lmid;
			else r=rmid;
		}
		printf("%.4lf\n",calc(l));
	}
	return 0;
}
