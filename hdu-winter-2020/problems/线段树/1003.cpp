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
int n,a[maxn],q;
int c[maxn][11][11];
int lowbit(int x){return x&-x;}
int sum(int x,int t)
{
	int res=0;
	while(x)
	{
		for(int i=1;i<=10;i++) res+=c[x][i][t%i];
		x-=lowbit(x);
	}
	return res;
}
void add(int x,int v,int k,int t)
{
	while(x<=n)
	{
		c[x][k][t]+=v;
		x+=lowbit(x);
	}
}
int main()
{
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++) read(a[i]);
		memset(c,0,sizeof(c));
		cin>>q;
		while(q--)
		{
			int opt;read(opt);
			if(opt==2)
			{
				int x;read(x);
				cout<<a[x]+sum(x,x)<<endl;
			}
			else
			{
				int x,y,k,c;
				read(x),read(y),read(k),read(c);
				add(x,c,k,x%k);
				add(y+1,-c,k,x%k);
			}
		}	
	} 
	return 0;
}

