#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
#define ll long long
using namespace std;
const int maxn=200050;
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
int T;
int a[maxn],num[maxn];
string s;
int main()
{
	T=read();
	while(T--)
	{
		ll ans=0;
		cin>>s;
		int n=s.size();
		num[n+1]=n+1;
		for(int i=n;i>=1;i--)
		{
			if(s[i-1]=='1') num[i]=i;
			else num[i]=num[i+1];
		}
		for(int i=1;i<=n;i++)
		{
			int res=0;
			for(int j=num[i];j<=n&&j<=num[i]+19;j++)
			{
				res=res*2+s[j-1]-'0';
				if(res==j-i+1) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
