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
int a[maxn],b[maxn],n,root;
int head[maxn],num,flag;
struct node{
	int v,nex;
}e[maxn];
void add(int u,int v)
{
	e[++num].nex=head[u];
	e[num].v=v;
	head[u]=num;
}
int calc_tree(int l1,int r1,int l2,int r2)
{
	if(l1>r1) return 0;
	int r=b[l2],pos;
	for(int i=l1;i<=r1;i++)
	{
		if(a[i]==r)
		{
			pos=i;
			break;
		}
	}
	int temp=pos-l1,v;
	if(v=calc_tree(l1,pos-1,l2+1,l2+temp))
	{
		add(r,v);
	}
	if(v=calc_tree(pos+1,r1,l2+temp+1,r2))
	{
		add(r,v);
	}
	return r;
}
void bfs(int s)
{
	queue<int> q;
	while(!q.empty()) q.pop();
	q.push(s);
	while(!q.empty())
	{
		int tt=q.size();
		vector<int> res;res.clear();
		for(int i=0;i<tt;i++)
		{
			int u=q.front();q.pop();
			res.push_back(u);
			for(int i=head[u];i;i=e[i].nex)
			{
				int v=e[i].v;
				q.push(v);
			}
		}
		for(int i=0;i<res.size();i++) 
		{
			if(flag) cout<<" "<<res[i];
			else
			{
				cout<<res[i];
				flag=1;
			}
		}
	}
	cout<<endl;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	calc_tree(1,n,1,n);
	root=b[1];
	bfs(root);
	return 0;
}

