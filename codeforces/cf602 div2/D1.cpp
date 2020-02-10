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
const int maxn=150;
int n,m;
ll a[maxn];
ll f[maxn][maxn],pre[maxn][maxn];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--) f[i][1]=max(a[i],f[i+1][1]);
	for(int i=n;i>=1;i--)
	{
		for(int len=1;len<=n-i+1;len++)
		{
			if(len<n-i+1) f[i][len]=f[i+1][len];
			if(f[i+1][len-1]+a[i]>f[i][len])
			{
				f[i][len]=f[i+1][len-1]+a[i];
			}
			
		}
	}
	cin>>m;
	while(m--)
	{
		int k,pos;
		cin>>k>>pos;
		int temp=k,tot=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i][temp]==f[i+1][temp-1]+a[i])
			{
				temp-=1;
				tot++;
				if(tot==pos)
				{
					cout<<a[i]<<endl;
					break;
				}
			}
		}
	}
	return 0;
}

