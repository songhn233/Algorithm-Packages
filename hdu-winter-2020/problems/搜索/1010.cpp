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
const int maxn=1050;
int vis[25][25][maxn];
int n,m,pan;
char a[25][25];
struct node{
	int x,y,s,dis;
	bool operator==(const node& t){
		return x==t.x&&y==t.y;
	}
};
node st,ed;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool calc(int x,int y)
{
	if(x<0||x>=n||y<0||y>=m||a[x][y]=='*') return false;
	return true;
}
void bfs()
{
	memset(vis,0,sizeof(vis));
	queue<node> q;
	q.push(st);
	while(!q.empty())
	{
		node t=q.front();q.pop();
		if(t==ed)
		{
			cout<<t.dis<<endl;
			return ;
		}
		if(t.dis>=pan-1) continue;
		for(int i=0;i<4;i++)
		{
			int tx=t.x+dx[i],ty=t.y+dy[i];
			if(!calc(tx,ty)) continue;
			if(a[tx][ty]>='A'&&a[tx][ty]<='Z')
			{
				int temp=a[tx][ty]-'A';
				if(t.s>>temp&1)
				{
					if(vis[tx][ty][t.s]) continue;
					vis[tx][ty][t.s]=1;
					q.push({tx,ty,t.s,t.dis+1});
					//cout<<"#1  "<<tx<<"  "<<ty<<"  "<<t.s<<"  "<<t.dis+1<<"---"<<endl;
				}
			}
			else if(a[tx][ty]>='a'&&a[tx][ty]<='z')
			{
				int temp=a[tx][ty]-'a';
				if(vis[tx][ty][t.s|(1<<(temp))]) continue;
				vis[tx][ty][t.s|(1<<temp)]=1;
				q.push({tx,ty,t.s|(1<<temp),t.dis+1});
				//cout<<"#2  "<<tx<<"  "<<ty<<"  "<<(t.s|(1<<temp))<<"  "<<t.dis+1<<"---"<<endl;
			}
			else if(!vis[tx][ty][t.s])
			{
				vis[tx][ty][t.s]=1;
				q.push({tx,ty,t.s,t.dis+1});
				//cout<<"#3  "<<tx<<"  "<<ty<<"  "<<t.s<<"  "<<t.dis+1<<"---"<<endl;
			}
			//cout<<tx<<"  "<<ty<<"---"<<endl;
		}
	}
	puts("-1");
	return ;
}
int main()
{
	while(~scanf("%d%d%d",&n,&m,&pan))
	{
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(a[i][j]=='@') st={i,j};
				if(a[i][j]=='^') ed={i,j};
			}
		}
		bfs();
	}
	return 0;
}

