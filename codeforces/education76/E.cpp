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
const int maxn=600050;
int n1,n2,n3,n;
int a[maxn],t1[maxn],t2[maxn],t3[maxn];
int f[maxn],c[maxn];
int lowbit(int x){return x&-x;}
int query(int x)
{
	int res=0;
	while(x)
	{
		res=max(res,c[x]);
		x-=lowbit(x);
	}
	return res;
}
void add(int x,int p)
{
	while(x<=n)
	{
		c[x]=max(c[x],p);
		x+=lowbit(x);
	}
}
int main()
{
	cin>>n1>>n2>>n3;
	F(i,1,n1) read(t1[i]);
	F(i,1,n2) read(t2[i]);
	F(i,1,n3) read(t3[i]);
	sort(t1,t1+n1+1);
	sort(t2,t2+n2+1);
	sort(t3,t3+n3+1);
	n=n1+n2+n3;
	for(int i=1;i<=n;i++)
	{
		if(i<=n1) a[i]=t1[i];
		else if(i<=n1+n2) a[i]=t2[i-n1];
		else a[i]=t3[i-n1-n2];
	}
	for(int i=1;i<=n;i++)
	{
		int temp=query(a[i]);
		f[i]=temp+1;
		add(a[i],f[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,f[i]);
	cout<<n-ans<<endl;
	return 0;
}

