#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=30050;
int n,m,fa[maxn],size[maxn];
int get(int x){if(x!=fa[x])fa[x]=get(fa[x]); return fa[x];}
void merge(int x,int y)
{
	x=get(x),y=get(y);
	if(x==y) return ;
	fa[x]=y;
	size[y]+=size[x];
}
int main()
{
	while(cin>>n>>m)
	{
		if(n==0&&m==0) break;
		for(int i=0;i<n;i++) fa[i]=i,size[i]=1;
		while(m--)
		{
			int t;cin>>t;
			int x;cin>>x;
			t--;
			while(t--)
			{
				int y;cin>>y;
				if(x<y) swap(x,y);
				merge(x,y);
			}
		}
		cout<<size[get(0)]<<endl;
	}
	return 0;
}


