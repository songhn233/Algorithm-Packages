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
int n,p;
struct matrix{
	int f[5][5];
};
matrix operator *(matrix a,matrix b)
{
	matrix c;
	memset(c.f,0,sizeof(c.f));
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			for(int k=1;k<=4;k++)
				c.f[i][j]=(c.f[i][j]+a.f[i][k]*b.f[k][j])%p;
	return c;
}
matrix ksm(matrix a,int b)
{
	matrix res;
	memset(res.f,0,sizeof(res.f));
	for(int i=1;i<=4;i++) res.f[i][i]=1;
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
	while(~scanf("%d%d",&n,&p))
	{
		matrix temp;
		memset(temp.f,0,sizeof(temp.f));
		temp.f[1][1]=1,temp.f[1][3]=1,temp.f[1][4]=1;
		temp.f[2][1]=1;temp.f[3][2]=1;temp.f[4][3]=1;
		if(n<=3)
		{
			if(n==0) puts("1");
			if(n==1) puts("2");
			if(n==2) puts("4");
			if(n==3) puts("6");
			continue;
		}
		n-=3;
		matrix res=ksm(temp,n);
		matrix s;
		memset(s.f,0,sizeof(s.f));
		s.f[1][1]=6;s.f[2][1]=4;s.f[3][1]=2,s.f[4][1]=1;
		matrix ans=res*s;
		cout<<ans.f[1][1]<<endl;
	}
	return 0;
}

