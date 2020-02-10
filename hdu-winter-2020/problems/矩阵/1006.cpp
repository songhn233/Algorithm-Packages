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
const int maxn=55;
int T;
int n,m,q;
struct matrix{
	int f[maxn][maxn];
};
matrix operator*(matrix a,matrix b)
{
	matrix c;
	memset(c.f,0,sizeof(c.f));
	for(int i=0;i<n*m;i++)
		for(int j=0;j<n*m;j++)
			for(int k=0;k<n*m;k++)
				c.f[i][j]=c.f[i][j]+a.f[i][k]*b.f[k][j];
	return c;
}
matrix ksm(matrix a,int b)
{
	matrix res;
	memset(res.f,0,sizeof(res.f));
	for(int i=0;i<n*m;i++) res.f[i][i]=1;
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
		cin>>n>>m;
		getchar();
		matrix a;
		memset(a.f,0,sizeof(a.f));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				int x1,y1,x2,y2,x3,y3,x4,y4;
				scanf("((%d,%d),(%d,%d),(%d,%d),(%d,%d))",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
				getchar();
                if(i==n-1&&j==m-1)  continue;
				a.f[i*m+j][(x1-1)*m+y1-1]=1;a.f[i*m+j][(x2-1)*m+y2-1]=1;
				a.f[i*m+j][(x3-1)*m+y3-1]=1;a.f[i*m+j][(x4-1)*m+y4-1]=1;
			}
		}
		cin>>q;
		while(q--)
		{
			int x;read(x);
			matrix temp=ksm(a,x);
			int flag=0;
			if(temp.f[0][n*m-1]==1) flag=1;
			if(flag)
			{
				for(int i=0;i<n*m-1;i++)
					if(temp.f[0][i]) flag=2;
				if(flag==2) puts("Maybe");
				else puts("True");
			}
			else puts("False");
		}
	}
	return 0;
}

