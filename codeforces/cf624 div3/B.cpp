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
const int maxn=150;
int T,n,m,p[maxn],a[maxn],mp[maxn];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		memset(mp,0,sizeof(mp));
		for(int i=1;i<=n;i++) read(a[i]);
		for(int i=1;i<=m;i++) read(p[i]),mp[p[i]]=1;
		for(int i=1;i<=n;i++)
		{
			if(mp[i])
			{
				
				int pos=i;
				while(pos<n&&mp[pos+1]) pos++;
				if(pos==n) sort(a+i,a+pos+1);
				else sort(a+i,a+pos+2);
			}
		}
		int flag=1;
		for(int i=1;i<n;i++)
		{
			if(a[i]>a[i+1])
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

