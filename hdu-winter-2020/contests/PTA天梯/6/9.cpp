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
const int maxn=100050;
int n,a[maxn];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
	}
	sort(a+1,a+n+1);
	int t;
	if((n/2)*2==n) t=n/2;
	else t=(n/2)+1;
	int ans=0;
	for(int i=n;i>=n-t+1;i--) ans+=a[i];
	for(int i=1;i<n-t+1;i++) ans-=a[i];
	cout<<"Outgoing #: "<<t<<endl; 
	cout<<"Introverted #: "<<n-t<<endl;
	cout<<"Diff = "<<ans<<endl;
	return 0;
}
