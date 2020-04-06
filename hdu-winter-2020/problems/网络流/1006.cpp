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
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=200050;
const int N=150;
int n,m,s,t,ans,maxflow;
int d[maxn],vis[maxn];
int head[maxn],num=1;
int incf[maxn],pre[maxn];
struct node{
	int v,w,c,nex;
}e[maxn];
void add(int u,int v,int w,int c)
{
	e[++num].v=v,e[num].w=w,e[num].c=c;
	e[num].nex=head[u],head[u]=num;
	e[++num].v=u,e[num].w=0,e[num].c=-c;
	e[num].nex=head[v],head[v]=num;
}
bool spfa()
{
	memset(vis,0,sizeof(vis));
	memset(d,0x3f,sizeof(d));
	queue<int> q;
	q.push(s);
	d[s]=0,vis[s]=1;
	incf[s]=inf;
	while(!q.empty())
	{
		int u=q.front();
		q.pop(),vis[u]=0;
		for(int i=head[u];i;i=e[i].nex)
		{
			if(!e[i].w) continue;
			int v=e[i].v;
			if(d[v]>d[u]+e[i].c)
			{
				d[v]=d[u]+e[i].c;
				incf[v]=min(incf[u],e[i].w);
				pre[v]=i;
				if(!vis[v]) q.push(v),vis[v]=1;
			}
		}
	}
	if(d[t]==inf) return false;
	return true;
}
void flow()
{
	int x=t;
	while(x!=s)
	{
		int i=pre[x];
		e[i].w-=incf[t];
		e[i^1].w+=incf[t];
		x=e[i^1].v;
	}
	maxflow+=incf[t];
	ans+=d[t];
}
char a[N][N];
struct edge{
    int x,y;
}M[N*N],H[N*N];
int num1,num2;
int main()
{
	while(~scanf("%d%d",&n,&m))
    {
        if(!n&&!m) break;
        num1=num2=0;num=1;
        mst(head,0);
        rep(i,0,n-1) cin>>a[i];
        rep(i,0,n-1)
        {
            rep(j,0,m-1)
            {
                if(a[i][j]=='m') M[++num1]={i,j};
                if(a[i][j]=='H') H[++num2]={i,j};
            }
        }
        s=0,t=num1+num2+1;
        rep(i,1,num1) add(0,i,1,0);
        rep(i,1,num1)
        {
            rep(j,1,num2)
            {
                int dis=abs(M[i].x-H[j].x)+abs(M[i].y-H[j].y);
                add(i,num1+j,1,dis);
            }
        }
        rep(i,1,num2) add(num1+i,num1+num2+1,1,0);
        maxflow=ans=0;
        while(spfa()) flow();
	    printf("%d\n",ans);
    }
	return 0;
}