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
int T,n;
int a[maxn],ans[maxn];
set<int> s;
int main()
{
	cin>>T;
	while(T--)
	{
		read(n);s.clear();
		int flag=1;
		for(int i=1;i<=n;i++) read(a[i]),s.insert(i);
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a[i-1]) ans[i]=a[i],s.erase(a[i]);
			else
			{
				int t=*s.begin();
				if(t>a[i]) 
				{
					flag=0;
					break;
				}
				ans[i]=t;
				s.erase(t);
			}
			if(!flag) break;
		}
		if(!flag) puts("-1");
		else
		{
			for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
			puts("");
		}
	}
	return 0;
}

