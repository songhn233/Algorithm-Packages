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
const int maxn=1050;
int T,n;
struct node{
	int x,y;
	bool operator<(const node&t) const{
		if(x==t.x) return y<t.y;
		return x<t.x;
	}
}a[maxn];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) read(a[i].x),read(a[i].y);
		sort(a+1,a+n+1);
		int px=0,py=0;
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i].x!=px&&a[i].y<py) flag=0;
			px=a[i].x,py=a[i].y;
		}
		if(!flag) puts("NO");
		else
		{
			int px=0,py=0;
			puts("YES");
			for(int i=1;i<=n;i++)
			{
				for(int j=px;j<a[i].x;j++) cout<<"R";
				for(int j=py;j<a[i].y;j++) cout<<"U";
				px=a[i].x,py=a[i].y;
			}
			puts("");
		}
	}
	return 0;
}
