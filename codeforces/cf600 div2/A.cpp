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
int n,T,a[maxn],b[maxn];
int main()
{
	read(T);
	while(T--)
	{
		read(n);
		for(int i=1;i<=n;i++) read(a[i]);
		for(int i=1;i<=n;i++) read(b[i]);
		int k=0,flag=1,tt=0;
		for(int i=1;i<=n;i++)
		{
			if(flag==0) break;
			if(a[i]!=b[i]&&a[i-1]==b[i-1]&&i>1) tt++;
			if(a[i]!=b[i]&&tt>1)
			{
				puts("NO");
				flag=0;
				break;
			}
			else if(a[i]!=b[i])
			{
				if(k==0)
				{
					if(b[i]-a[i]<0) 
					{
						puts("NO");
						flag=0;
						break;
					}
					else k=b[i]-a[i];
				}
				else if(b[i]-a[i]!=k) 
				{
					puts("NO");
					flag=0;
					break;
				}
			}
		}
		if(flag) puts("YES");
	}
	return 0;
}

