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
int n,m,a[105][105],q;
int pan[105][105];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
vector<int> temp;
bool calc(int x,int y)
{
	if(x<1||x>n||y<1||y>m) return false;
	if(pan[x][y]) return false;
	return true;
}
int head[maxn],num,vis[maxn],match[maxn];
struct node{
	int v,nex;
}e[maxn];
void add(int u,int v)
{
	e[++num].nex=head[u];
	e[num].v=v;
	head[u]=num;
}
bool dfs(int u)
{
	for(int i=head[u];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(!vis[v])
		{
			vis[v]=1;
			if(!match[v]||dfs(match[v]))
			{
				match[v]=u;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		if(!n&&!m) break;
		cin>>q;
		memset(pan,0,sizeof(pan));
		num=0;memset(head,0,sizeof(head));
		memset(match,0,sizeof(match));
		temp.clear();
		for(int i=1;i<=q;i++)
		{
			int x,y;read(x),read(y);
			pan[x][y]=1;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if((i+j)%2)
				{
					if(pan[i][j]) continue;
					temp.push_back(i*m+j);
					for(int k=0;k<4;k++)
					{
						int tx=i+dx[k],ty=j+dy[k];
						if(!calc(tx,ty)) continue;
						add(i*m+j,tx*m+ty);
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<temp.size();i++)
		{
			int t=temp[i];
			memset(vis,0,sizeof(vis));
			if(dfs(t)) ans++;
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(((i+j)%2==0)&&(pan[i][j]==0))
				{
					if(match[i*m+j])
					{
						if(match[i*m+j]%m==0) printf("(%d,%d)--(%d,%d)\n",i,j,(match[i*m+j]/m)-1,m);
						else printf("(%d,%d)--(%d,%d)\n",i,j,match[i*m+j]/m,match[i*m+j]%m);
					}
				}
			}
		}
		cout<<endl;
	}
	return 0;
}

