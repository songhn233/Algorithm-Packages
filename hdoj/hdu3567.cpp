#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
#define PSI pair<string,int>
using namespace std;
const int maxn=400000;
int t,T;
string s,e;
char ss[]={'u','d','r','l'};
map<string,int> mp;
int sx,sy;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int pre[maxn],num=1,opt[maxn];
int calc(int x,int y){return x*3+y;}
bool pan(int x,int y)
{
	if(x<0||x>=3||y<0||y>=3) return false;
	return true;
}
void bfs()
{
	mp.clear();
	num=1;
	memset(pre,0,sizeof(pre));
	queue<PSI> q;
	q.push(make_pair(s,1));
	while(!q.empty())
	{
		string temp=q.front().first;
		int id=q.front().second;
		q.pop();
		if(temp==e)
		{
			printf("Case %d: %d\n",t,mp[temp]);
			for(int i=id;i;i=pre[i])
			{
				if(i==1) break;
				cout<<ss[opt[i]];
			}
			puts("");
			return ;
		}
		int pos=temp.find('X');
		int x=pos/3,y=pos%3;
		for(int i=0;i<4;i++)
		{
			string nex=temp;
			int tx=x+dx[i],ty=y+dy[i];
			if(!pan(tx,ty)) continue;
			swap(nex[pos],nex[calc(tx,ty)]);
			if(mp[nex]) continue;
			mp[nex]=mp[temp]+1;
			pre[++num]=id;
			opt[num]=i;
			q.push(make_pair(nex,num));
		}
	}
}
int main()
{
	cin>>T;
	for(t=1;t<=T;t++)
	{
		cin>>s>>e;
		bfs();
	}
	return 0;
}
