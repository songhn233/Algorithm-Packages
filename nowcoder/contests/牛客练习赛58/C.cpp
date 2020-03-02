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
const int maxn=25;
int n,m,k;
int a[maxn][maxn],sum;
int r[maxn],c[maxn],ans,vr[maxn],vc[maxn],s[maxn];
void dfs(int d)
{
	if(d==k)
	{
		int temp=0;
		for(int i=1;i<=n;i++)
		{
			if(vr[i]) temp+=s[i];
			else
			{
				for(int j=1;j<=m;j++)
				{
					if(vc[j]) temp+=a[i][j];
				}
			}
		}
		ans=max(ans,temp);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vr[i]) continue;
		vr[i]=1;
		dfs(d+1);
		vr[i]=0;
	}
	for(int j=1;j<=m;j++)
	{
		if(vc[j]) continue;
		vc[j]=1;
		dfs(d+1);
		vc[j]=0;
	}
}
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) read(a[i][j]),sum+=a[i][j],s[i]+=a[i][j];
	if(k>=min(n,m))
	{
		cout<<sum<<endl;
	}
	else
	{
		dfs(0);
		cout<<ans<<endl;
	}
	return 0;
}

