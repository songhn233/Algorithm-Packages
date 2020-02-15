#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<ctime>
#include<map>
#include<set>
#include<cstdlib>
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
const int maxn=105;
int a[maxn][maxn],n,b[maxn],flag[maxn],ans;
void calc()
{
	memset(flag,0,sizeof(flag));
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(!flag[i])
		{
			res++;
			for(int j=i+1;j<=n;j++)
				if(!a[b[i]][b[j]]) flag[j]=1;
		}
	}
	ans=max(ans,res);
}
int main()
{
	while(~scanf("%d",&n))
	{
		if(!n) break;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) read(a[i][j]);
		for(int i=1;i<=n;i++) b[i]=i;
		ans=0;
		for(int i=1;i<=1000;i++)
		{
			for(int j=1;j<=n;j++)
				swap(b[j],b[rand()%j+1]);
			calc();
		}
		cout<<ans<<endl;
	}
	return 0;
}

