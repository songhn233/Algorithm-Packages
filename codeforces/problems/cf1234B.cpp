#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
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
const int maxn=200050;
int n,m,a[maxn];
map<int,bool> mp;
int sta[maxn],top;
int main()
{
	read(n),read(m);
	F(i,1,n)
	{
		int x;read(x);
		if(mp[x]) continue;
		mp[x]=true;
		sta[++top]=x;
		if(top>m) mp[sta[top-m]]=false;
	}
	if(top-m+1<1) cout<<top<<endl;
	else cout<<m<<endl;
	for(int i=top;i>=max(top-m+1,1);i--) printf("%d ",sta[i]);
	puts("");
	return 0;
}


