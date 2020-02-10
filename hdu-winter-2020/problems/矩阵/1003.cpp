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
const int maxn=205;
int n,k,p;
struct matrix{
	int f[maxn][maxn];
};
matrix operator *(matrix a,matrix b)
{
	matrix c;
	memset(c.f,0,sizeof(c.f));
	for(int i=1;i<=2*n;i++)
		for(int j=1;j<=2*n;j++)
			for(int k=1;k<=2*n;k++)
				c.f[i][j]=(c.f[i][j]+a.f[i][k]*b.f[k][j])%p;
	return c;
}
matrix ksm(matrix a,int b)
{
	matrix res;
	memset(res.f,0,sizeof(res.f));
	for(int i=1;i<=2*n;i++) res.f[i][i]=1;
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
	cin>>n>>k>>p;
	matrix A;
	memset(A.f,0,sizeof(A.f));
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>A.f[i][j];
	matrix temp;
	memset(temp.f,0,sizeof(temp.f));
	for(int i=1;i<=n;i++) temp.f[i][i]=1;
	for(int i=1;i<=n;i++) 
	{
		for(int j=1;j<=n;j++)
			temp.f[i][j+n]=A.f[i][j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			temp.f[n+i][n+j]=A.f[i][j];
	}
	
	matrix res=ksm(temp,k);
	matrix s;
	memset(s.f,0,sizeof(s.f));
	for(int i=1;i<=n;i++) s.f[i+n][i]=1;
	matrix ans=res*s;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			if(j!=n) cout<<ans.f[i][j]<<" ";
			else cout<<ans.f[i][j]<<endl;
	}
	return 0;
}

