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
const int maxn=255;
const double eps=1e-9;
int T,n;
struct edge{
	int v;
	double x,y,z;
}t[maxn<<1];
struct node{
	int id,v;
	double dis;
	bool operator<(const node &t) const{
		if(fabs(dis-t.dis)<eps) return v>t.v;
		return dis<t.dis;
	}
}a[maxn][maxn],b[maxn][maxn];
int match[maxn],idx[maxn],pmatch[maxn];
double calc_dis(int x,int y)
{
	edge t1=t[x],t2=t[y];
	double x1=t1.x,y1=t1.y,z1=t1.z;
	double x2=t2.x,y2=t2.y,z2=t2.z;
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
}
bool calc(int id,int x,int y)
{
	for(int i=1;i<=n;i++)
	{
		if(b[id][i].id==x) return true;
		if(b[id][i].id==y) return false;
	}
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		memset(match,0,sizeof(match));
		memset(pmatch,0,sizeof(pmatch));
		for(int i=1;i<=n;i++)
		{
			int id;cin>>id;
			cin>>t[id].v>>t[id].x>>t[id].y>>t[id].z;
		}
		for(int i=1;i<=n;i++)
		{
			int id;cin>>id;
			cin>>t[n+id].v>>t[n+id].x>>t[n+id].y>>t[n+id].z;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				a[i][j]={j,t[n+j].v,calc_dis(i,n+j)};
			}
			sort(a[i]+1,a[i]+n+1);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				b[i][j]={j,t[j].v,calc_dis(n+i,j)};
			}
			sort(b[i]+1,b[i]+n+1);
		}
		queue<int> q;
		while(!q.empty()) q.pop();
		for(int i=1;i<=n;i++) q.push(i);
		for(int i=1;i<=n;i++) idx[i]=1;
		while(!q.empty())
		{
			int u=q.front();q.pop();
			int v=a[u][idx[u]].id;
			if(!match[v])
			{
				match[v]=u;
				pmatch[u]=v;
				idx[u]++;
				continue;
			}
			else
			{
				int temp=match[v];
				if(calc(v,u,temp))
				{
					match[v]=u;
					pmatch[u]=v;
					q.push(temp);
				}
				else
				{
					idx[u]++;
					q.push(u);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			cout<<i<<" "<<pmatch[i]<<endl;
		}
		cout<<endl;
	}
	return 0;
}

