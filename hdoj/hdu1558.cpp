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
const int maxn=1050;
int T,n,num;
int sgn(double x){if(fabs(x)<eps)return 0; return x<0?-1:1;}
struct point{
	double x,y;
	point operator-(const point&t){return {x-t.x,y-t.y};}
	point operator+(const point&t){return {x+t.x,y+t.y};}
	point operator*(const double&t){return {x*t,y*t};}
	point operator/(const double&t){return {x/t,y/t};}
	bool operator==(const point&t){
		return sgn(x-t.x)==0&&sgn(y-t.y)==0;
	}
};
struct segment{
	point a,b;
}seg[maxn];
int size[maxn],fa[maxn];
int get(int x){if(x!=fa[x]) fa[x]=get(fa[x]); return fa[x];}
void merge(int x,int y)
{
	x=get(x),y=get(y);
	if(x==y) return ;
	size[y]+=size[x];
	fa[x]=y;
}
double cross(point t1,point t2){return t1.x*t2.y-t1.y*t2.x;}
bool segment_cross(segment t1,segment t2)
{
	point a=t1.a,b=t1.b,c=t2.a,d=t2.b;
	double c1=cross(b-a,c-a),c2=cross(b-a,d-a);
	double d1=cross(d-c,a-c),d2=cross(d-c,b-c);
	return sgn(c1)*sgn(c2)<=0&&sgn(d1)*sgn(d2)<=0;
}
int main()
{
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		if(t!=1) cout<<endl;
		num=0;
		cin>>n;
		for(int i=0;i<n;i++) fa[i]=i,size[i]=1;
		char opt[2];
		for(int i=1;i<=n;i++)
		{
			cin>>opt;
			if(opt[0]=='P')
			{
				double x1,y1,x2,y2;
				cin>>x1>>y1>>x2>>y2;
				seg[num++]={{x1,y1},{x2,y2}};
				for(int i=0;i<num-1;i++)
				{
					if(segment_cross(seg[i],seg[num-1])) merge(i,num-1);
				}
			}
			else
			{
				int t;cin>>t;
				t--;
				cout<<size[get(t)]<<endl;
			}
		}
	}
	return 0;
}

