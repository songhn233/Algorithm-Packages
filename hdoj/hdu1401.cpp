#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
using namespace std;
const int maxn=10;
struct node{
	int x[4],y[4];
	bool operator<(const node&t) const{
		int p=1;
		for(int i=0;i<4;i++) if(x[i]!=t.x[i]||y[i]!=t.y[i]) p=0;
		if(p) return true;
		else return false;
	}
};
node s,t;
int vis[maxn][maxn][maxn][maxn][maxn][maxn][maxn][maxn];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
map<node,int> mp;
void bfs_s()
{
	mp.clear();
	mp[s]=1;
	queue<node> q;
	q.push(s);
	for(int T=1;T<=4;T++)
	{
		int temp=q.size();
		for(int tt=0;tt<temp;tt++)
		{
			node t=q.front();q.pop();
			for(int p=0;p<4;p++)
			{
				for(int i=0;i<4;i++)
				{
					int tx=t.x[i]+dx[i],ty=t.y[i]+dy[i];
					if(tx<1||tx>8||ty<1||ty>8) continue;
					node nex=t;
					nex.x[p]=tx,nex.y[p]=ty;
					if(mp[nex]) continue;
					mp[nex]=1;
					q.push(nex);
				}
			}
		}
	}
}
void bfs_t()
{
	mp[t]=2;
	queue<node> q;
	q.push(t);
	for(int T=1;T<=4;T++)
	{
		int temp=q.size();
		for(int tt=0;tt<temp;tt++)
		{
			node t=q.front();q.pop();
			if(mp[t]==1) 
			{
				puts("YES");
				return ;
			}
			for(int p=0;p<4;p++)
			{
				for(int i=0;i<4;i++)
				{
					int tx=t.x[i]+dx[i],ty=t.y[i]+dy[i];
					if(tx<1||tx>8||ty<1||ty>8) continue;
					node nex;
					for(int pos=0;pos<4;pos++) nex.x[pos]=t.x[pos],nex.y[pos]=t.y[pos];
					nex.x[p]=tx,nex.y[p]=ty;
					if(mp[nex]==2) continue;
					mp[nex]=2;
					q.push(nex);
				}
			}
		}
	}
	puts("NO");
	return ;
}
int main()
{
	while(cin>>s.x[0]>>s.y[0])
	{
		for(int i=1;i<4;i++) cin>>s.x[i]>>s.y[i];
		for(int i=0;i<4;i++) cin>>t.x[i]>>t.y[i];
		bfs_s();
		bfs_t();
	}
	
	return 0;
}
