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
const int maxn=100050;
int n,m,k;
int fa[maxn];
ll ans[maxn],temp[maxn],size[maxn];
PII mp[maxn],mmp[maxn];
int get(int x){if(x!=fa[x]) fa[x]=get(fa[x]); return fa[x];}
void merge(int x,int y)
{
	x=get(x),y=get(y);
	if(x==y) return ;
	fa[x]=y;
	size[y]+=size[x];
}
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i,size[i]=1;
	for(int i=1;i<=m;i++)
	{
		int x,y;read(x),read(y);
		merge(x,y);
		mp[i]=make_pair(x,y);
	}
	for(int i=1;i<=k;i++)
	{
		int x,y;read(x),read(y);
		mmp[i]=make_pair(x,y);
	}
	for(int i=1;i<=m;i++)
	{
		int x=mp[i].first,y=mp[i].second;
		if(get(x)==get(y)) ans[x]--,ans[y]--;
	}
	for(int i=1;i<=k;i++)
	{
		int x=mmp[i].first,y=mmp[i].second;
		if(get(x)==get(y)) ans[x]--,ans[y]--;
	}
	for(int i=1;i<=n;i++)
	{
		ans[i]+=size[get(i)]-1;
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}

