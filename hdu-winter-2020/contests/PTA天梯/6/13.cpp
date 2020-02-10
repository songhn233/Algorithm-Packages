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
const double g=9.8;
const double eps=1e-7;
double m,p;
double ans;
int main()
{
	cin>>m>>p;
	m*=0.01;
	p*=0.01;
	p=1-p;
	double e=1000;
	double v=(2*e)/m;
	
	while(e>eps)
	{
		ans+=v/(2*g);
		e*=p;
		v=(2*e)/m;
	}
	printf("%.3lf\n",ans*2);
	return 0;
}
