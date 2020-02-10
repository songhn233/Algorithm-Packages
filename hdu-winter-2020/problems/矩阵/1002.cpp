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
const int p=9973;
int T,n,k;
struct matrix{
	int f[11][11];
	matrix operator*(const matrix&t){
		matrix c;
		memset(c.f,0,sizeof(c.f));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					c.f[i][j]=(c.f[i][j]+f[i][k]*t.f[k][j])%p;
				}
			}
		}
		return c;
	}
};
matrix ksm(matrix a,int b)
{
	matrix res;
	memset(res.f,0,sizeof(res.f));
	for(int i=1;i<=n;i++) res.f[i][i]=1;
	while(b)
	{
		if(b&1) res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		matrix s;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>s.f[i][j];
		matrix res=ksm(s,k);
		ll ans=0;
		for(int i=1;i<=n;i++) ans=(ans+res.f[i][i])%p;
		cout<<ans<<endl;
	}
	return 0;
}

