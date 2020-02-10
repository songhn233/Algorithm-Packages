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
const int maxn=3050;
int n,m;
int v[maxn],w[maxn],f[maxn][maxn];
int p[maxn],num;
int main()
{
	cin>>n>>m;
	int maxx=0,pos=0;
	for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
	for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m-1;j++)
        {
            f[i][j]=f[i-1][j];
            if(j-v[i]>=0) f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]);
        }
    }
	int temp=m-1;
	for(int i=n;i>=1;i--)
    {
        if(temp-v[i]>=0&&f[i][temp]==f[i-1][temp-v[i]]+w[i])
        {
            temp-=v[i];
        }
        else p[++num]=w[i];
    }
	sort(p+1,p+num+1);
	cout<<f[n][m-1]+p[num]<<endl;
	return 0;
}

