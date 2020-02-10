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
const int maxn=20050;
int T,n,m;
int w[maxn];
int head[maxn],num,s[maxn],cnt;
int vis[maxn],dis[maxn],pre[maxn];
struct node{
	int v,nex;
}e[maxn];
void add(int u,int v)
{
	e[++num].nex=head[u];
	e[num].v=v;
	head[u]=num;
}
vector<int> ans;
void spfa()
{
	memset(vis,0,sizeof(vis));
	memset(dis,0,sizeof(dis));
	queue<int> q;
	q.push(1);
	dis[1]=0;
	vis[1]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=e[i].nex)
		{
			int v=e[i].v;
			if(dis[v]<dis[u]+w[v])
			{
				dis[v]=dis[u]+w[v];
				pre[v]=u;
				if(!vis[v])
				{
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
}
int main()
{
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		cin>>n;
		ans.clear();
		memset(head,0,sizeof(head));
		num=cnt=0;
		for(int i=1;i<=n;i++) read(w[i]);
		w[n+1]=0;
		cin>>m;
		for(int i=1;i<=m;i++)
		{
			int x,y;read(x),read(y);
			if(x>y) swap(x,y);
			add(x,y);
		}
		spfa();
		printf("CASE %d#\n",t);
		printf("points : %d\n",dis[n+1]);
		cout<<"circuit : ";
		int pos=n+1;
		while(pos!=1) ans.push_back(pos),pos=pre[pos];
		ans.push_back(1);
		for(int i=ans.size()-1;i>=0;i--) 
		{
			if(i!=0) cout<<ans[i]<<"->";
			else cout<<1<<endl;
		}
		if(t!=T) puts("");
	}
	return 0;
}

