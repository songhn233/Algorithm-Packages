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
const int maxn=1000;
int n,a[maxn],b[maxn];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n+1;i<=2*n;i++) a[i]=a[i-n];
	int ans=0;
	for(int i=2;i<=n;i++)
		ans+=abs(a[i]-a[1]);
	int temp=0;
	for(int i=1;i<=n-1;i++)
		temp+=abs(a[i]-a[n]);
	cout<<max(ans,temp)<<endl;
	return 0;
}

