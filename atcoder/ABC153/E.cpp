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
const int maxm=20000010;
int h,n,v[maxn],w[maxn],f[maxm],maxx;
int main()
{
	cin>>h>>n;
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(int i=1;i<=n;i++) cin>>v[i]>>w[i],maxx=max(v[i],maxx);
	for(int i=1;i<=n;i++)
	{
		for(int j=v[i];j<=h+maxx;j++)
			f[j]=min(f[j],f[j-v[i]]+w[i]);	
	}
	int ans=inf;
	for(int i=h;i<=h+maxx;i++) ans=min(ans,f[i]);
	cout<<ans<<endl;
	return 0;
}

