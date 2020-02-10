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
const int maxn=550;
int T,n,idx[maxn];
struct node{
	int c,id;
	double dis;
	bool operator<(const node&t) const{
		if(dis!=t.dis)return dis<t.dis;
		else return c>t.c; 
	}
}a[maxn][maxn],b[maxn];
struct edge{
	int id,c;
	double x,y,z;
}t1[maxn],t2[maxn];
double calc_dis(edge t1,edge t2)
{
	double x1=t1.x,y1=t1.y,z1=t1.z;
	double x2=t2.x,y2=t2.y,z2=t2.z;
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
}
queue<int> q;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int id,c;
			double x,y,z;
			cin>>id>>c>>x>>y>>z;
			t1[i]={id,c,x,y,z};
		}
		for(int i=1;i<=n;i++)
		{
			int id,c;
			double x,y,z;
			cin>>id>>c>>x>>y>>z;
			t2[i]={id,c,x,y,z};
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				a[i][j]={t2[j].id,t2[j].c,calc_dis(t1[i],t2[j])};
			}
		}
		for(int i=1;i<=n;i++) sort(a[i]+1,a[i]+n+1);
		while(!q.empty()) q.pop();
		for(int i=1;i<=n;i++) q.push(i);
		for(int i=1;i<=n;i++) idx[i]=1;
		while(!q.empty())
		{
			int u=q.front();q.pop();
			int v=a[u][idx[u]].id;
			if(!b[v])
			{
				b[v]=u;
				idx[u]++;
			}
			else
			{
				int temp=b[v];
				calc_cmp(u,temp);
			}
		}
	}
	return 0;
}

