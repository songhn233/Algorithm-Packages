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
const int maxn=100005;
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
int n;
int main()
{
	while(cin>>n)
	{
		if(!n) break;
		for(int i=0;i<n;i++) cin>>p[i].x>>p[i].y;
		int flag=1;
		for(int i=0;i<n;i++)
		{
			if(cross(p[(i+1)%n]-p[i],p[(i+2)%n]-p[i])<=0) 
			{
				flag=0;
				break;
			}
		}
		if(flag) puts("convex");
		else puts("concave");
	}
	return 0;
}

