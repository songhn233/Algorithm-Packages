#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=150;
const double eps=1e-9;
int n;
struct point{
	double x,y;
	point operator-(const point&t){
		return {x-t.x,y-t.y};
	}
};
struct segment{
	point p1,p2;
}a[maxn];
double cross(point t1,point t2){return (t1.x*t2.y-t1.y*t2.x);}
int sgn(double x)
{
	if(fabs(x)<eps) return 0;
	return x<0?-1:1;
}
bool cross_segment(segment t1,segment t2)
{
	point a=t1.p1,b=t1.p2,c=t2.p1,d=t2.p2;
	double c1=cross(b-a,c-a),c2=cross(b-a,d-a);
	double c3=cross(d-c,a-c),c4=cross(d-c,b-c);
	return sgn(c1)*sgn(c2)<=0&&sgn(c3)*sgn(c4)<=0;
}
int main()
{
	while(cin>>n)
	{
		if(!n) break;
		for(int i=1;i<=n;i++)
		{
			double x,b,c,d;
			cin>>x>>b>>c>>d;
			a[i]={{x,b},{c,d}};
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans+=cross_segment(a[i],a[j])?1:0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
