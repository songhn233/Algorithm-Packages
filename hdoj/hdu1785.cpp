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
const int maxn=205;
const int inf=0x3f3f3f3f;
const double eps=1e-8;
int sgn(double x){if(fabs(x)<eps) return 0; return x<0?-1:1;}

struct point{
	double x,y;
	point operator-(const point&t){return {x-t.x,y-t.y};}
	point operator+(const point&t){return {x+t.x,y+t.y};}
	point operator*(const double&t){return {x*t,y*t};}
	point operator/(const double&t){return {x/t,y/t};}
	bool operator==(const point&t){
		return sgn(x-t.x)==0&&sgn(y-t.y)==0;
	}
}p[maxn];
double dot(point t1,point t2){return t1.x*t2.x+t1.y*t2.y;}
double len(point t){return sqrt(dot(t,t));}
double calc(double x,double y)
{
	point t={x,y},s={1.0,0};
	return acos(dot(t,s)/(len(t)*len(s)));
}
bool cmp(point &t1,point &t2)
{
	return calc(t1.x,t1.y)<calc(t2.x,t2.y);
}
int n;
int main()
{
	while(cin>>n)
	{
		if(n<0) break;
		for(int i=0;i<n;i++)
		{
			double x,y;cin>>x>>y;
			p[i]={x,y};
		}
		sort(p,p+n,cmp);
		for(int i=0;i<n;i++) 
		{
			if(i!=n-1) printf("%.1f %.1f ",p[i].x,p[i].y);
			else printf("%.1f %.1f\n",p[i].x,p[i].y);
		}
	}
	return 0;
}

