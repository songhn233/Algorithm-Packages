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
int T,m,n;
int v[maxn],w[maxn],f[maxn];
int main()
{
	cin>>T;
	while(T--)
	{
		int t1,t2;cin>>t1>>t2;
		m=t2-t1;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
		memset(f,0x3f,sizeof(f));
		f[0]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=v[i];j<=m;j++)
				f[j]=min(f[j],f[j-v[i]]+w[i]);
		}
		if(f[m]==inf) puts("This is impossible.");
		else printf("The minimum amount of money in the piggy-bank is %d.\n",f[m]);
	}
	return 0;
}

