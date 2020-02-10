#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int maxn=105;
int s,n,m,vis[maxn][maxn][maxn];
struct node{
	int v1,v2,v3,d;
};
node st;
void bfs()
{
	if(s&1) {puts("NO");return ;}
	st={s,0,0,0};
	memset(vis,0,sizeof(vis));
	queue<node> q;
	while(!q.empty()) q.pop();
	q.push(st);
	while(!q.empty())
	{
		node t=q.front();q.pop();
		if((t.v1==t.v2&&(t.v3==0))||(t.v1==t.v3&&(t.v2==0))||(t.v2==t.v3&&(t.v1==0))) 
		{
			cout<<t.d<<endl;
			return ;
		}
		if(t.v1&&(n-t.v2))
		{
			node nex;
			if(t.v1>n-t.v2) nex={t.v1-n+t.v2,n,t.v3,t.d+1};
			else nex={0,t.v2+t.v1,t.v3,t.d+1};
			if(!vis[nex.v1][nex.v2][nex.v3])q.push(nex),vis[nex.v1][nex.v2][nex.v3]=1;
		}
		
		if(t.v1&&(m-t.v3))
		{
			node nex;
			if(t.v1>m-t.v3) nex={t.v1-m+t.v3,t.v2,m,t.d+1};
			else nex={0,t.v2,t.v3+t.v1,t.d+1};
			if(!vis[nex.v1][nex.v2][nex.v3])q.push(nex),vis[nex.v1][nex.v2][nex.v3]=1;
		}
		
		if(t.v2&&(s-t.v1))
		{
			node nex;
			if(t.v2>s-t.v1) nex={s,t.v2-s+t.v1,t.v3,t.d+1};
			else nex={t.v1+t.v2,0,t.v3,t.d+1};
			if(!vis[nex.v1][nex.v2][nex.v3])q.push(nex),vis[nex.v1][nex.v2][nex.v3]=1;
		}
		
		if(t.v2&&(m-t.v3))
		{
			node nex;
			if(t.v2>m-t.v3) nex={t.v1,t.v2-m+t.v3,m,t.d+1};
			else nex={t.v1,0,t.v3+t.v2,t.d+1};
			if(!vis[nex.v1][nex.v2][nex.v3])q.push(nex),vis[nex.v1][nex.v2][nex.v3]=1;
		}
		
		if(t.v3&&(s-t.v1))
		{
			node nex;
			if(t.v3>s-t.v1) nex={s,t.v2,t.v3-s+t.v1,t.d+1};
			else nex={t.v1+t.v3,t.v2,0,t.d+1};
			if(!vis[nex.v1][nex.v2][nex.v3])q.push(nex),vis[nex.v1][nex.v2][nex.v3]=1;
		}
		
		if(t.v3&&(n-t.v2))
		{
			node nex;
			if(t.v3>n-t.v2) nex={t.v1,n,t.v3-n+t.v2,t.d+1};
			else nex={t.v1,t.v2+t.v3,0,t.d+1};
			if(!vis[nex.v1][nex.v2][nex.v3])q.push(nex),vis[nex.v1][nex.v2][nex.v3]=1;
		}
	}
	
	puts("NO");
}
int main()
{
	while(cin>>s>>n>>m)
	{
		if(s==0&&n==0&&m==0) break;
		bfs();
	}
	return 0;
}
