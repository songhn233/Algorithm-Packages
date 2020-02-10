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
int n,m,k,fa[maxn];
int findx(int x){if(x!=fa[x]) fa[x]=findx(fa[x]); return fa[x];}
map<PII,bool> mp;
void merge(int x,int y)
{
	x=findx(x),y=findx(y);
	if(x==y) return ;
	fa[x]=y;
}
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		if(z==1)
		{
			merge(x,y);
		}
		else
		{
			mp[make_pair(x,y)]=mp[make_pair(y,x)]=true;
		}
	}
	while(k--)
	{
		int x,y;
		cin>>x>>y;
		if(findx(x)==findx(y)&&mp[make_pair(x,y)]==false) puts("No problem");
		else if(findx(x)!=findx(y)&&mp[make_pair(x,y)]==false) puts("OK");
		else if(mp[make_pair(x,y)]==true&&findx(x)==findx(y)) puts("OK but...");
		else if(mp[make_pair(x,y)]==true) puts("No way");
	}
	return 0;
}

