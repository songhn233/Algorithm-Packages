#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=1050;
int m,n,p;
int f[maxn];
int s[maxn],sg[maxn];
void init()
{
	f[0]=f[1]=1;
	for(int i=2;;i++)
	{
		f[i]=f[i-1]+f[i-2];
		if(f[i]>=1000) break;
	}
}
int calc(int n)
{
	memset(s,0,sizeof(s));memset(sg,0,sizeof(sg));
	for(int i=1;i<=n;i++)
	{
		memset(s,0,sizeof(s));
		for(int j=1;i-f[j]>=0;j++) s[sg[i-f[j]]]=1;
		for(int j=0;;j++)
			if(!s[j]) {sg[i]=j;break;}
	}
	return sg[n];
}
int main()
{
	init();
	while(cin>>m>>n>>p)
	{
		if(m==0&&n==0&&p==0) break;
		int t1=calc(m);
		int t2=calc(n);
		int t3=calc(p);
		int ans=t1^t2^t3;
		if(ans) puts("Fibo");
		else puts("Nacci");
	}
	return 0;
}


