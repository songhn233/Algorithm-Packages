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
const int maxn=50050;
int T,n,num;
ll f[100];
int main()
{
	cin>>T;
	f[1]=1,f[2]=2;
	for(int i=3;i<=81;i++) f[i]=f[i-1]+f[i-2];
	while(T--)
	{
		cin>>n;
		if(n==0) puts("1");
		else if(n==1) puts("3");
		else cout<<f[n]+f[n+1]<<endl;
	}
	return 0;
}

