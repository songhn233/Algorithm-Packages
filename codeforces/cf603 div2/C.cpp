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
int ans[maxn],num;
int main()
{
	cin>>T;
	while(T--)
	{
		int res=0;
		num=0;
		cin>>n;
		int r;
		for(int i=1;i<=n;i=r+1)
		{
			ans[++num]=n/i;
			r=n/(n/i);
			res++;
			if(r>n) r=n;
			i=r;
		}
		cout<<res+1<<endl;
		printf("0 ");
		for(int i=num;i>=1;i--) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}

