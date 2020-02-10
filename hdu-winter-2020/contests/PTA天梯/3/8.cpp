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
const int N=105;
int n1,m1,n2,m2;
int a[maxn][maxn],b[maxn][maxn],c[maxn][maxn];
int main()
{
	cin>>n1>>m1;
	for(int i=1;i<=n1;i++) for(int j=1;j<=m1;j++) read(a[i][j]);
	cin>>n2>>m2;
	for(int i=1;i<=n2;i++) for(int j=1;j<=m2;j++) read(b[i][j]);
	if(m1!=n2) printf("Error: %d != %d\n",m1,n2);
	else
	{
		cout<<n1<<" "<<m2<<endl;
		for(int k=1;k<=N;k++)
		{
			for(int i=1;i<=N;i++)
				for(int j=1;j<=N;j++)
					c[i][j]+=a[i][k]*b[k][j];
		}
		for(int i=1;i<=n1;i++)
		{
			for(int j=1;j<=m2;j++)
			{
				if(j!=m2) cout<<c[i][j]<<" ";
				else cout<<c[i][j]<<endl;
			}
		}
	}
	return 0;
}

