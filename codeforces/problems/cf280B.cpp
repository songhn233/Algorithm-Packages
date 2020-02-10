#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<stack>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=100050;
int n,a[maxn];
int s[maxn],top;
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		while(top&&s[top]<a[i]) top--;
		if(top) ans=max(ans,a[i]^s[top]);
		
		s[++top]=a[i];
	}
	reverse(a+1,a+n+1);
	top=0;
	memset(s,0,sizeof(s));
	for(int i=1;i<=n;i++)
	{
		while(top&&s[top]<a[i]) top--;
		if(top) ans=max(ans,a[i]^s[top]);
		
		s[++top]=a[i];
	}
	cout<<ans<<endl;
	return 0;
}

