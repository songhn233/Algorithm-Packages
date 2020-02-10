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
const int maxn=200050;
int T,n,a[maxn],m,p[maxn],s[maxn];
int c[maxn];
int main()
{
	read(T);
	while(T--)
	{
		read(n);
		int mx=0;
		for(int i=1;i<=n;i++) read(a[i]),mx=max(mx,a[i]);
		for(int i=1;i<=n+1;i++) c[i]=0;
		read(m);
		int maxx=0;
		for(int i=1;i<=m;i++) 
		{
			read(p[i]),read(s[i]);
			c[s[i]]=max(c[s[i]],p[i]);
			maxx=max(maxx,p[i]);
		}
		for(int i=n;i>=1;i--) c[i]=max(c[i],c[i+1]);
		
		if(maxx<mx) puts("-1");
		else
		{
			int pos=1,num=1,temp=0,ans=0;
			while(pos<=n)
			{
				temp=max(temp,a[pos]);
				while(c[num]>=temp) 
				{
					num++;
					temp=max(temp,a[pos+num-1]);
				}
				pos+=num-1;
				num=1;temp=0;
				ans++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

