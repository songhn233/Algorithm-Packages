#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<map>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=200050;
int q,n;
int mp[maxn];
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
int main()
{
	q=read();
	while(q--)
	{
		n=read();
		for(int i=1;i<=n;i++) 
		{
			int x;x=read();
			mp[x]++;
		}
		int ans=0;
		sort(mp+1,mp+n+1);
		int pos=inf;
		for(int i=n;i>=1;i--)
		{
			pos--;
			pos=min(pos,mp[i]);
			if(pos==0) break;
			ans+=pos;
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++) mp[i]=0;
	}
	return 0;
}
