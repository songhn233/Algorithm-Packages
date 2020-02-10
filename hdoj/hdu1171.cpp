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
const int maxn=255000;
int n,m;
int v[maxn],c[maxn],f[maxn];
int main()
{
	while(cin>>n)
	{
		if(n<0) break;
		m=0;
		for(int i=1;i<=n;i++) cin>>v[i]>>c[i],m+=v[i]*c[i];
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
		{
			for(int j=m/2;j>=0;j--)
			{
				for(int k=0;k*v[i]<=j&&k<=c[i];k++)
					f[j]=max(f[j],f[j-k*v[i]]+k*v[i]);
			}
		}
		cout<<m-f[m/2]<<" "<<f[m/2]<<endl;
	}
	return 0;
}

