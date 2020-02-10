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
const int maxm=20005;
int T,n,num;
struct node{
	int u,v;
	double w;
	bool operator<(const node&t) const{
		return w<t.w;
	}
}e[maxm];
struct edge{
	int x,y;
}a[maxn];
int fa[maxn];
int get(int x){if(x!=fa[x])fa[x]=get(fa[x]); return fa[x];}
double calc(int p1,int p2)
{
	int x1=a[p1].x,x2=a[p2].x,y1=a[p1].y,y2=a[p2].y;
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void kruskal()
{
	sort(e+1,e+num+1);
	for(int i=1;i<=n;i++) fa[i]=i;
	int cnt=0;
	double ans=0.0;
	for(int i=1;i<=num;i++)
	{
		int x=e[i].u,y=e[i].v;
		x=get(x),y=get(y);
		if(x==y) continue;
		fa[x]=y;
		ans+=e[i].w;
		cnt++;
		if(cnt==n-1) break;
	}
	int temp=get(1);
	for(int i=2;i<=n;i++) 
	{
		if(get(i)!=temp)
		{
			puts("oh!");
			return ;
		}
	}
	printf("%.1lf\n",ans*100);
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		num=0;
		for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				double temp=calc(i,j);
				if(temp<10||temp>1000) continue;
				e[++num]={i,j,temp};
			}
				
		kruskal();
	}
	return 0;
}

