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
const int maxn=200050;
int n,fa[maxn];
int get(int x){if(x!=fa[x]) fa[x]=get(fa[x]); return fa[x];}
struct node{
	int x,y;
}query[maxn];
int h[maxn],num;
map<int,int> mp;
int main()
{
	while(~scanf("%d",&n))
	{
		num=0;mp.clear();
		for(int i=1;i<=n;i++) 
		{
			read(query[i].x),read(query[i].y);
			h[++num]=query[i].x;h[++num]=query[i].y;
		}
		sort(h+1,h+num+1);
		num=unique(h+1,h+num+1)-h-1;
		for(int i=1;i<=num;i++) fa[i]=i;
		for(int i=1;i<=n;i++)
		{
			int x=lower_bound(h+1,h+num+1,query[i].x)-h;
			int y=lower_bound(h+1,h+num+1,query[i].y)-h;
			x=get(x),y=get(y);
			if(x==y) continue;
			fa[x]=y;
		}
		for(int i=1;i<=num;i++) mp[get(i)]++;
		int ans=1;
		for(auto x:mp) ans=max(ans,x.second);
		printf("%d\n",ans);
	}
	return 0;
}

