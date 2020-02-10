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
const int maxn=20;
int n,ans;
int a[maxn],x[maxn][maxn],y[maxn][maxn];
int lowbit(int x){return x&-x;}
int count(int x)
{
	int res=0;
	while(x) x-=lowbit(x),res++;
	return res;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=1;j<=a[i];j++)
		{
			cin>>x[i][j]>>y[i][j];
			x[i][j]--;
		}
	}
	for(int i=0;i<(1<<n);i++)
	{
		int flag=1;
		for(int j=0;j<n;j++)
		{
			if(i>>j&1)
			{
				for(int k=1;k<=a[j+1];k++)
				{
					if((i>>x[j+1][k]&1)^y[j+1][k]) flag=0;
				}
			}
		}
		if(!flag) continue;
		ans=max(ans,count(i));
	}
	cout<<ans<<endl;
	return 0;
}

