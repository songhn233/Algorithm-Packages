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
const double eps=1e-8;
const int maxn=2050;
const double pi= acos(-1);
int n,T;
double r;
int sgn(double x){if(fabs(x)<eps) return 0; return x<0?-1:1;}
struct point{
	double x,y;
	point operator-(const point&t){return {x-t.x,y-t.y};}
	point operator+(const point&t){return {x+t.x,y+t.y};}
	point operator*(const double&t){return {x*t,y*t};}
	point operator/(const double&t){return {x/t,y/t};}
	bool operator<(const point&t){
		return sgn(x-t.x)<0||(sgn(x-t.x)==0&&sgn(y-t.y)<0);
	}
	bool operator==(const point&t){
		return sgn(x-t.x)==0&&sgn(y-t.y)==0;
	}
}p[maxn];
point ans[maxn];
double dis(point t1,point t2){return sqrt((t1.x-t2.x)*(t1.x-t2.x)+(t1.y-t2.y)*(t1.y-t2.y));}
double cross(point t1,point t2){return (t1.x*t2.y-t1.y*t2.x);}
int convex_full(point *p,int n,point *ans)
{
	sort(p,p+n);
	n=unique(p,p+n)-p;
	int pos=0;
	for(int i=0;i<n;i++)
	{
		while(pos>1&&sgn(cross(ans[pos-1]-ans[pos-2],p[i]-ans[pos-2]))<=0) pos--;
		ans[pos++]=p[i];
	}
	int t=pos;
	for(int i=n-2;i>=0;i--)
	{
		while(pos>t&&sgn(cross(ans[pos-1]-ans[pos-2],p[i]-ans[pos-2]))<=0) pos--;
		ans[pos++]=p[i];
	}
	if(n>1) pos--;
	return pos;
}

int main()
{
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		if(t!=1) printf("\n");
		cin>>n>>r;
		for(int i=0;i<n;i++)
		{
			double x,y;cin>>x>>y;
			p[i]={x,y};
		}
		int res=convex_full(p,n,ans);
		if(res==1)printf("%.0f\n",2*pi*r);
		else if(res==2) printf("%.0f\n",dis(ans[0],ans[1])+2*pi*r);
		else
		{
			double cnt=0.0;
			for(int i=0;i<res;i++) cnt+=dis(ans[i],ans[(i+1)%n]);
			printf("%.0f\n",cnt+2*pi*r);
		}
	}
	return 0;
}
