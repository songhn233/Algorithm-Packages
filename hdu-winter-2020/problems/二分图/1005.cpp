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
const int maxn=10050;
int T,n;
pair<int,int> a[55],b[55];
int calc_num(char c)
{
	if(c=='T') return 10;
	else if(c=='J') return 11;
	else if(c=='Q') return 12;
	else if(c=='K') return 13;
	else if(c=='A') return 14;
	else return c-'0';
}
int calc_t(char c)
{
	if(c=='C') return 1;
	else if(c=='D') return 2;
	else if(c=='S') return 3;
	else if(c=='H') return 4;
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
	cin>>T;
	while(T--)
	{
		cin>>n;
		memset(head,0,sizeof(head));num=0;
		memset(match,0,sizeof(match));
		for(int i=1;i<=n;i++)
		{
			string s;cin>>s;
			int x=calc_num(s[0]);
			int y=calc_t(s[1]);
			b[i]=make_pair(x,y);
		}
		for(int i=1;i<=n;i++)
		{
			string s;cin>>s;
			int x=calc_num(s[0]);
			int y=calc_t(s[1]);
			a[i]=make_pair(x,y);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[i].first>b[j].first) add(i,n+j);
				else if(a[i].first==b[j].first)
				{
					if(a[i].second>b[j].second) add(i,n+j);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i)) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

