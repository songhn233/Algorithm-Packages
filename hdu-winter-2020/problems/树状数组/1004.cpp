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
const int N=1001;
int T,n,c[maxn][maxn];
int lowbit(int x){return x&-x;}
void add(int x,int y,int p)
{
	for(int i=x;i<=N;i+=lowbit(i))
	{
		for(int j=y;j<=N;j+=lowbit(j))
		{
			c[i][j]+=p;
		}
	}
}
int sum(int x,int y)
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
int getnum(int x,int y)
{
	return sum(x,y)-sum(x-1,y)-sum(x,y-1)+sum(x-1,y-1);
}
int main()
{
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		memset(c,0,sizeof(c));
		printf("Case %d:\n",t);
		cin>>n;
		for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) add(i,j,1);
		for(int i=1;i<=n;i++)
		{
			char opt[5];
			cin>>opt;
			if(opt[0]=='A') 
			{
				int x,y,z;
				read(x),read(y),read(z);
				x++,y++;
				add(x,y,z);
			}
			else if(opt[0]=='D')
			{
				int x,y,z;
				read(x),read(y),read(z);
				x++,y++;
				int t=getnum(x,y);
				if(t>=z) add(x,y,-z);
				else add(x,y,-t);
			}
			else if(opt[0]=='M')
			{
				int x1,y1,x2,y2,z;
				read(x1),read(y1),read(x2),read(y2),read(z);
				x1++,y1++,x2++,y2++;
				int t=getnum(x1,y1);
				if(t>=z) add(x1,y1,-z),add(x2,y2,z);
				else add(x1,y1,-t),add(x2,y2,t);
			}
			else
			{
				int x1,y1,x2,y2;
				read(x1),read(y1),read(x2),read(y2);
				x1++,y1++,x2++,y2++;
				if(x1>x2) swap(x1,x2);
				if(y1>y2) swap(y1,y2);
				cout<<sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1)<<endl;
			}
		}
	}
	return 0;
}

