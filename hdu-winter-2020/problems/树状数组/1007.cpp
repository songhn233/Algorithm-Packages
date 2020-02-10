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
int T,n,m,c[maxn][maxn];
int lowbit(int x){return x&-x;}
void add(int x,int y,int p)
{
	for(int i=x;i<=n;i+=lowbit(i))
	{
		for(int j=y;j<=n;j+=lowbit(j))
		{
			c[i][j]+=p;
		}
	}
}
int query(int x,int y)
{
	int res=0;
	for(int i=x;i>0;i-=lowbit(i))
	{
		for(int j=y;j>0;j-=lowbit(j))
		{
			res+=c[i][j];
		}
	}
	return res;
}
int main()
{
	cin>>T;
	while(T--)
	{
		memset(c,0,sizeof(c));
		cin>>n>>m;
		n++;
		for(int i=1;i<=m;i++)
		{
			char opt[5];
			cin>>opt;
			if(opt[0]=='C')
			{
				int x1,y1,x2,y2;
				read(x1),read(y1),read(x2),read(y2);
				add(x1,y1,1);add(x2+1,y1,-1),add(x1,y2+1,-1),add(x2+1,y2+1,1);
			}
			else
			{
				int x,y;
				read(x),read(y);
				cout<<query(x,y)%2<<endl;
			}
		}
		if(T) cout<<endl;
	}
	return 0;
}

