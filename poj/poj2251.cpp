#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int maxn=35;
const int inf=0x3f3f3f3f;
struct node{
	int x,y,l;
	node(int l=0,int x=0,int y=0):l(l),x(x),y(y){}
	bool operator==(const node&t)
	{
		if(x==t.x&&y==t.y&&l==t.l) return true;
		return false;
	}
};
node s,e;
int L,n,m,d[maxn][maxn][maxn];
char a[maxn][maxn][maxn];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool pan(int l,int x,int y)
{
	if(l<1||l>L) return false;
	if(x<0||x>n-1||y<0||y>m-1) return false;
	if(a[l][x][y]=='#') return false;
	if(d[l][x][y]!=inf) return false;
	return true;
}
void bfs()
{
	queue<node> q;
	while(!q.empty()) q.pop();
	q.push(s);
	memset(d,0x3f,sizeof(d));
	d[s.l][s.x][s.y]=0;
	while(!q.empty())
	{
		node u=q.front();q.pop();
		//cout<<"---"<<u.l<<" "<<u.x<<" "<<u.y<<endl;
		if(u==e)
		{
			printf("Escaped in %d minute(s).\n",d[u.l][u.x][u.y]);
			return ;
		}
		for(int i=0;i<4;i++)
		{
			int tx=u.x+dx[i],ty=u.y+dy[i];
			if(!pan(u.l,tx,ty)) continue;
			d[u.l][tx][ty]=d[u.l][u.x][u.y]+1;
			q.push(node(u.l,tx,ty));
		}
		if(pan(u.l+1,u.x,u.y))
		{
			d[u.l+1][u.x][u.y]=d[u.l][u.x][u.y]+1;
			q.push(node(u.l+1,u.x,u.y));
		}
		if(pan(u.l-1,u.x,u.y))
		{
			d[u.l-1][u.x][u.y]=d[u.l][u.x][u.y]+1;
			q.push(node(u.l-1,u.x,u.y));
		}
	}
	puts("Trapped!");
	return ;
}
int main()
{
	while(cin>>L>>n>>m)
	{
		if(L==0&&n==0&&m==0) break;
		for(int l=1;l<=L;l++)
		{
			for(int i=0;i<n;i++) cin>>a[l][i];
		}
		for(int l=1;l<=L;l++)
		{
			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
					if(a[l][i][j]=='S') s=node(l,i,j);
					else if(a[l][i][j]=='E') e=node(l,i,j);
		}
		bfs();
	}
	return 0;
}
