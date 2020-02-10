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
ll T,n;
ll a[maxn],s1[maxn],s2[maxn];
int main()
{
	cin>>T;
	while(T--)
	{
		read(n);
		for(int i=1;i<=n;i++) read(a[i]);
		for(int i=0;i<=n+1;i++) s1[i]=s2[i]=0;
		int flag=1;
		for(int i=1;i<=n;i++) 
		{
			s1[i]=s1[i-1]+a[i];
			if(s1[i]<=0) 
			{
				flag=0;
				break;
			}
		}
		
		for(int i=n;i>=1;i--) 
		{
			s2[i]=s2[i+1]+a[i];
			if(s2[i]<=0) 
			{
				flag=0;
				break;
			}
		}
		
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}

