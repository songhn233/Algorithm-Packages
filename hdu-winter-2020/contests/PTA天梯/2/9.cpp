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
int n,m,opt[maxn],k;
map<int,int> mp; 
PII e[maxn];
int ans[maxn];
int fa[maxn];
int find(int x){if(x!=fa[x])fa[x]=find(fa[x]); return fa[x];}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return ;
	fa[x]=y;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;read(x),read(y);
		merge(x,y);
		e[i]=make_pair(x,y);
	}
	cin>>k;
	for(int i=1;i<=k;i++) 
	{
		read(opt[i]);
	}
	int cnt=0;
	for(int i=0;i<n;i++) 
	{
		if(find(i)==i) cnt++;
	}
	for(int i=1;i<=k;i++)
	{
		int u=opt[i];
		mp[u]=1;
		int flag=0;
		for(int j=0;j<n;j++) fa[j]=j;
		for(int j=1;j<=m;j++)
		{
			if(mp[e[j].first]||mp[e[j].second]) continue;
			merge(e[j].first,e[j].second);
		}
		for(int j=0;j<n;j++) if(find(j)==j) flag++;
		//cout<<flag<<"---"<<endl;
		if(flag==cnt||flag==cnt+1) printf("City %d is lost.\n",u);
		else printf("Red Alert: City %d is lost!\n",u);
		if(i==k&&k==n) puts("Game Over");
		cnt=flag;
	}
	return 0;
}

