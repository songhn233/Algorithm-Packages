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
int k,p,n;
struct matrix{
	int f[maxn][maxn];
};
matrix operator*(matrix a,matrix b)
{
	matrix c;
	memset(c.f,0,sizeof(c.f));
	for(int i=1;i<=10;i++)
		for(int j=1;j<=10;j++)
			for(int k=1;k<=10;k++)
				c.f[i][j]=(c.f[i][j]+a.f[i][k]*b.f[k][j])%p;
	return c;
}
matrix ksm(matrix a,int b)
{
	matrix res;
	memset(res.f,0,sizeof(res.f));
	for(int i=1;i<=10;i++) res.f[i][i]=1;
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
	while(~scanf("%d%d",&k,&p))
	{
		matrix temp;
		memset(temp.f,0,sizeof(temp.f));
		for(int i=1;i<=10;i++) cin>>temp.f[1][i];
		for(int i=2;i<=10;i++) temp.f[i][i-1]=1;
		
		if(k<10) cout<<k%p<<endl;
		else
		{
			matrix s;
			memset(s.f,0,sizeof(s.f));
			for(int i=1;i<=10;i++) s.f[i][1]=10-i;
			k-=9;
			matrix res=ksm(temp,k);
			matrix ans=res*s;
			cout<<ans.f[1][1]<<endl;
		}
	}
	return 0;
}

