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
int T,x,n,a[maxn];
string s;
int main()
{
	cin>>T;
	while(T--)
	{
		read(n),read(x);
		cin>>s;
		int t=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='0') t++;
			else t--;
			a[i]=t;
		}
		if(t==0)
		{
			int ans=0,flag=1;
			if(x==0) ans=1;
			for(int i=0;i<n;i++)
			{
				if(a[i]==x) flag=0;
			}
			if(!flag) puts("-1");
			else cout<<ans<<endl;
		}
		else
		{
			int ans=0;
			if(x==0) ans=1;
			for(int i=0;i<n;i++)
			{
				if((x-a[i])%t==0&&(x-a[i])/t>=0) ans++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

