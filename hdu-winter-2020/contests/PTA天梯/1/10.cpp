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
const int maxn=55;
int n,p1,p2;
int head[50],num=0;
int a[maxn],b[maxn];
struct node{
	int v,nex;
}e[50];
void add(int u,int v)
{
	e[++num].nex=head[u];
	e[num].v=v;
	head[u]=num;
}
int dfs(int l1,int r1,int l2,int r2)
{
	if(l2>r2) return 0;
	int root,t1,t2;
	root=a[r1];
	t1=l2;
	while(b[t1]!=root) t1++;
	t2=t1-l2;
	int v1,v2;
	if(v1=dfs(l1,l1+t2-1,l2,t1-1)) add(root,v1);
	if(v2=dfs(l1+t2,r1-1,t1+1,r2)) add(root,v2);
	return root;
}
int flag=0;
void bfs(int s)
{
	queue<int> q;
	while(!q.empty()) q.pop();
	q.push(s);
	vector<int> ans;
	ans.clear();
	while(!q.empty())
	{
		int tt=q.size();
		ans.clear();
		for(int i=0;i<tt;i++)
		{
			int u=q.front();q.pop();
			ans.push_back(u);
			for(int i=head[u];i;i=e[i].nex)
			{
				int v=e[i].v;
				q.push(v);
			}
		}
		for(int i=(int)ans.size()-1;i>=0;i--) 
		{
			if(flag) 
			{
				cout<<" "<<ans[i];
			}
			else 
			{
				flag=1;
				cout<<ans[i];
			}
		}
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	dfs(1,n,1,n);
	bfs(a[n]);
	cout<<endl;
	return 0;
}

