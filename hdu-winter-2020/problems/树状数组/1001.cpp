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
const int maxn=50050;
int T,n,c[maxn];
int lowbit(int x){return x&-x;}
void add(int x,int p)
{
	while(x<=n)
	{
		c[x]+=p;
		x+=lowbit(x);
	}
}
int query(int x)
{
	int res=0;
	while(x)
	{
		res+=c[x];
		x-=lowbit(x);
	}
	return res;
}
int main()
{
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		printf("Case %d:\n",t);
		cin>>n;
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++)
		{
			int x;read(x);
			add(i,x);
		}
		string s;
		while(cin>>s)
		{
			if(s=="End") break;
			if(s=="Query")
			{
				int x,y;read(x),read(y);
				cout<<query(y)-query(x-1)<<endl;
			}
			else if(s=="Add")
			{
				int x,y;read(x),read(y);
				add(x,y);
			}
			else
			{
				int x,y;read(x),read(y);
				add(x,-y);
			}
		}
	}
	return 0;
}

