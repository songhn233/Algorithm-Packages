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
const int maxn=150;
int n;
struct point{
	int x,y;
	point operator=(const point&t){
		return {t.x,t.y};
	}
	point operator-(const point&t){
		return {x-t.x,y-t.y};
	}
	point operator+(const point&t){
		return {x+t.x,y+t.y};
	}
};
point p[maxn];
int cross(point a,point b){
	return a.x*b.y-a.y*b.x;
}
int main()
{
	while(cin>>n)
	{
		if(n==0) break;
		for(int i=1;i<=n;i++) cin>>p[i].x>>p[i].y;
		double ans=0.0;
		for(int i=1;i<=n;i++) 
		{
			if(i==n) ans+=cross(p[n],p[1]);
			else ans+=cross(p[i],p[i+1]);
		}
		
		printf("%.1lf\n",ans*0.5);
	}
	return 0;
}

