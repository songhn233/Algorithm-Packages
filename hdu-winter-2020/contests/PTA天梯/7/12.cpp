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
struct node{
	int id,val,cnt;
	bool operator<(const node&t) const{
		if(val==t.val)
		{
			if(cnt==t.cnt) return id<t.id;
			return cnt>t.cnt;
		}
		return val>t.val;
	}
}a[maxn];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) a[i].id=i;
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;cin>>x>>y;
			a[i].val-=y;
			a[x].cnt++;
			a[x].val+=y;
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		double ans=a[i].val*0.01;
		printf("%d %.2lf\n",a[i].id,ans);
	}
	return 0;
}

