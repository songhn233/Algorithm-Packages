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
const int mod=1e9+7; 
const int N=100000;
const int maxn=100050;
ll f[maxn][2];
ll n,m;
void init(int n)
{
	f[1][1]=1,f[1][0]=1,f[0][0]=1,f[0][1]=1;
	for(int i=2;i<=n;i++)
	{
		f[i][1]=(f[i-1][0]+f[i-2][0])%mod;
		f[i][0]=(f[i-1][1]+f[i-2][1])%mod;
	}
		
}
int main()
{
	init(N);
	cin>>n>>m;
	cout<<((((f[n][1]-1+f[m][1])*2)%mod+mod)%mod)<<endl;
	return 0;
}

