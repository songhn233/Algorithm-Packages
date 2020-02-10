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
const int maxn=10050;
int n;
int head[maxn],num,w[maxn],a[maxn];
int main()
{
	cin>>n;
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		if(i==1) continue;
		if(i%2==0)
		{
			if(a[i]<=a[i/2])
			{
				flag=0;
				break;
			}
		}
		else
		{
			if(a[i]>=a[i/2])
			{
				flag=0;
				break;
			}
		}
	}
	if(!flag) puts("NO");
	else puts("YES");
	return 0;
}

