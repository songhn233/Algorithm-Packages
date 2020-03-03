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
const int maxn=500050;
int n,m;
int c[26][maxn];
char s[maxn];
int lowbit(int x){return x&-x;}
void add(int t,int x,int p)
{
	while(x<=n)
	{
		c[t][x]+=p;
		x+=lowbit(x);
	}
}
int query(int t,int x)
{
	int res=0;
	while(x)
	{
		res+=c[t][x];
		x-=lowbit(x);
	}
	return res;
}
int main()
{
	cin>>n;
	cin>>(s+1);
	cin>>m;
	for(int i=1;i<=n;i++) add(s[i]-'a',i,1);
	while(m--)
	{
		int opt;read(opt);
		if(opt==1)
		{
			int x;char y;
			cin>>x>>y;
			add(s[x]-'a',x,-1);
			add(y-'a',x,1);
			s[x]=y;
		}
		else
		{
			int ans=0;
			int x,y;read(x),read(y);
			for(int i=0;i<26;i++)
			{
				if(query(i,y)-query(i,x-1)) ans++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

