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
const int maxn=300050;
ll n,k,a[maxn],f[maxn];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<k;i++) f[i]=inf;
	ll temp=-a[1];
	for(int i=k;i<=n;i++)
	{	
		f[i]=temp+a[i];
		temp=min(temp,f[i-k+1]-a[i-k+2]);
	}
	cout<<f[n]<<endl;
	return 0;
}

