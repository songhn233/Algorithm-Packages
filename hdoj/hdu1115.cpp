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
const int maxn=1000050;
const double eps=1e-8;
int T,n;
struct point{
	double x,y;
	point operator-(const point&t){
		return {x-t.x,y-t.y};
	}
	point operator+(const point&t){
		return {x+t.x,y+t.y};
	}
	point operator*(const double&t){
		return {x*t,y*t};
	}
	point operator/(const double&t){
		return {x/t,y/t};
	}
}p[maxn];
double cross(point t1,point t2){return t1.x*t2.y-t1.y*t2.x;}
int sgn(double x)
{
	if(fabs(x)<eps) return 0;
	return x<0?-1:1;
}
double polygon_area(point *p,int n)
{
	double res=0.0;
	for(int i=0;i<n;i++) res+=cross(p[i],p[(i+1)%n]);
	return res*0.5;
}
int main()
{
	//ios::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			double x,y;cin>>x>>y;
			p[i]={x,y};
		}
		point ans{0,0};
		if(sgn(polygon_area(p,n))==0) printf("%.2lf %.2lf\n",ans.x,ans.y);
		else
		{
			for(int i=0;i<n;i++) ans=ans+(p[i]+p[(i+1)%n])*cross(p[i],p[(i+1)%n]);
			ans=ans/(polygon_area(p,n)*6.0);
			printf("%.2lf %.2lf\n",ans.x,ans.y);
		}
	}
	return 0;
}

