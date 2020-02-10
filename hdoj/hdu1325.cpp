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
const int maxn=100050;
const int N=100000;
int fa[maxn];
int x,y,T,du[maxn],vis[maxn];
int get(int x){if(x!=fa[x]) fa[x]=get(fa[x]);return fa[x];}
int main()
{
	while(cin>>x>>y)
	{
		int maxx=0;
		if(x<0||y<0) break;
		T++;
		memset(vis,0,sizeof(vis));
		memset(du,0,sizeof(du));
		for(int i=1;i<=N;i++) fa[i]=i;
		if(x==0&&y==0)
		{
			printf("Case %d is a tree.\n",T);
		}
		else
		{
			int flag=0;
			maxx=max(x,y);
			vis[x]=vis[y]=1;
			du[y]++;
			x=get(x),y=get(y);
			if(x==y) flag=1;
			else fa[y]=x;
			while(cin>>x>>y)
			{
				if(x==0&&y==0) break;
				vis[x]=vis[y]=1;
				du[y]++;
				x=get(x),y=get(y);
				if(x==y) flag=1;
				else fa[y]=x;
				maxx=max(maxx,max(x,y));
			}
			if(flag)
			{
				printf("Case %d is not a tree.\n",T);
				continue;
			}
			for(int i=1;i<=maxx;i++) 
				if(vis[i]&&du[i]>1) 
				{
					printf("Case %d is not a tree.\n",T);
					flag=1;
					break;
				}
			if(!flag)
			{
				int pan=0,temp;
				for(int i=1;i<=maxx;i++)
				{
					if(vis[i])
					{
						temp=get(i);
						break;
					}
				}
				for(int i=1;i<=maxx;i++) 
				{
					if(vis[i]&&temp!=get(i)) 
					{
						printf("Case %d is not a tree.\n",T);
						pan=1;
						break;
					}
				}
				if(!pan) printf("Case %d is a tree.\n",T);
			}
		}
	}
	return 0;
}
