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
const int maxn=105;
const double eps=1e-8;
int n,k,cnt[maxn];
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
struct segment{
	point a,b;
}seg[maxn][maxn];
double cross(point t1,point t2){return (t1.x*t2.y-t1.y*t2.x);}
int sgn(double x)
{
	if(fabs(x)<eps) return 0;
	return x<0?-1:1;
}
bool segment_cross(segment t1,segment t2)
{
	point a=t1.a,b=t1.b,c=t2.a,d=t2.b;
	double c1=cross(b-a,c-a),c2=cross(b-a,d-a);
	double d1=cross(d-c,a-c),d2=cross(d-c,b-c);
	return sgn(c1)*sgn(c2)<=0&&sgn(d1)*sgn(d2)<=0;
}
int main()
{
	while(cin>>n)
	{
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		cnt[i]=k-1;
		for(int j=1;j<=k;j++)
		{
			double x,y;cin>>x>>y;
			p[j]={x,y};
		}
		for(int j=1;j<=k-1;j++)
		{
			seg[i][j]={p[j],p[j+1]};
		}
	}
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		if(!flag) break;
		for(int j=i+1;j<=n;j++)
		{
			if(!flag) break;
			for(int k=1;k<=cnt[i];k++)
			{
				if(!flag) break;
				for(int l=1;l<=cnt[j];l++)
				{
					if(segment_cross(seg[i][k],seg[j][l]))
					{
						flag=0;
						break;
					}
				}
			}
		}
	}
	if(flag) puts("No");
	else puts("Yes");
	}
	return 0;
}

