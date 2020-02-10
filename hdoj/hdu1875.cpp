#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=150;
const int maxm=5050;
int n,m,vis[maxn],T;
double a[maxn][maxn],d[maxn];
double prim()
{
	for(int i=1;i<=n;i++) d[i]=inf;
	memset(vis,0,sizeof(vis));
	d[1]=0;
	double res=0.0;
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		int pos=0;double minx=inf;
		for(int j=1;j<=n;j++)
			if((!vis[j])&&(d[j]<minx||pos==0)) pos=j,minx=d[j];
		
		if(d[pos]==inf)
		{
			flag=1;
			break;
		}
		res+=d[pos];
		vis[pos]=1;
		for(int j=1;j<=n;j++)
			if(!vis[j]) d[j]=min(d[j],a[pos][j]);
	}
	if(!flag) printf("%.1lf\n",res*100);
	else puts("oh!");
}
struct node{
	int x,y;
}p[maxm];
double calc(int t1,int t2)
{
	double x1=p[t1].x,x2=p[t2].x,y1=p[t1].y,y2=p[t2].y;
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]=inf;
		for(int i=1;i<=n;i++)
		{
			int x,y;cin>>x>>y;
			p[i]={x,y};
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				double temp=calc(i,j);
				if(temp<10||temp>1000) continue;
				a[i][j]=a[j][i]=temp;
			}
				
		prim();
	}
	return 0;
}


