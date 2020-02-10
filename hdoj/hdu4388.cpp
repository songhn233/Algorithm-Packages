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
int T,n;
int lowbit(int x){return x&-x;}
int getnum(int x)
{
	int res=0;
	while(x) x-=lowbit(x),res++;
	return res;
}
int main()
{
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		cin>>n;
		int res=0;
		for(int i=1;i<=n;i++)
		{
			int x;cin>>x;
			res+=getnum(x)-1;
		}
		int flag;
		if(res&1) flag=1;
		else flag=0;
		if(flag) printf("Case %d: Yes\n",t);
		else printf("Case %d: No\n",t);
	}
	return 0;
}


