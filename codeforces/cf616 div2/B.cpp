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
int T,n,a[maxn];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) read(a[i]);
		int flag=0,pre=0,pan=1,tt=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=n-i) continue;
			else tt=0;
		}
		if(tt) puts("Yes");
		else
		{
			for(int i=1;i<=n;i++)
		{
			if(flag==0)
			{
				if(a[i]>=i-1) continue;
				else
				{
					flag=1;
					pre=min(a[i-1]-1,a[i]);
					if(pre<0)
					{
						pan=0;
						break;
					}
				}
			}
			else
			{
				if(pre==0) pan=0;
				else pre=min(pre-1,a[i]);
			}
		}
		if(!pan) puts("No");
		else puts("Yes");
		}
		
	}
	return 0;
}

