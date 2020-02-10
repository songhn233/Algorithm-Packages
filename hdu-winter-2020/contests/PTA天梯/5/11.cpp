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
int n,g,k;
struct node{
	string s;
	int c;
	bool operator<(const node&t) const{
		if(t.c==c) return s<t.s;
		return c>t.c;
	}
}a[maxn];
int main()
{
	cin>>n>>g>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s>>a[i].c;
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].c>=g) ans+=50;
		else if(a[i].c>=60) ans+=20;
	}
	cout<<ans<<endl;
	int t=0,p=0;
	for(int i=1;i<=n;i++)
	{
		if(i>=2&&a[i].c==a[i-1].c) p++;
		else 
		{
			t++;
			t+=p;
			p=0;
		}
		if(t>k) break;
		cout<<t<<" "<<a[i].s<<" "<<a[i].c<<endl;
	}
	return 0;
}
