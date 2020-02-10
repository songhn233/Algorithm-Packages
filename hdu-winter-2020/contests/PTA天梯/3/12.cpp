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
const int N=10000;
const int maxn=10050;
map<int,bool> mp;
int n,q,fa[maxn];
int find(int x){if(x!=fa[x]) fa[x]=find(fa[x]); return fa[x];}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return ;
	fa[x]=y;
}
int main()
{
	cin>>n;
	for(int i=1;i<=N;i++) fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		int k;read(k);
		int x,y;
		read(x);
		mp[x]=true;
		for(int j=1;j<k;j++)
		{
			read(y);mp[y]=true;
			merge(x,y);
		}
	}
	int ans=0;
	int tt=mp.size();
	for(int i=1;i<=N;i++)
	{
		if(mp[i]==false) continue;
		if(find(i)==i) ans++;
	}
	cout<<tt<<" "<<ans<<endl;
	cin>>q;
	while(q--)
	{
		int x,y;
		read(x),read(y);
		if(find(x)==find(y)) puts("Y");
		else puts("N");
	}
	return 0;
}

