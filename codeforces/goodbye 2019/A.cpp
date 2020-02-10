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
int T;
int n,k1,k2;
int a[maxn],b[maxn]; 
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>k1>>k2;
		int pan=0;
		for(int i=1;i<=k1;i++) 
		{
			read(a[i]);
			if(a[i]==n) pan=1;
		}
		for(int i=1;i<=k2;i++)
		{
			read(b[i]);
			if(b[i]==n) pan=2;
		}
		if(pan==1) puts("YES");
		else puts("NO");
	}
	
	return 0;
}

