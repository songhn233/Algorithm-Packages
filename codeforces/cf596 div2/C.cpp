#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=200050;
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
int n,p;
int lowbit(int x){return x&-x;}
int getnum(int x)
{
	int res=0;
	while(x) x-=lowbit(x),res++;
	return res;
}
int main()
{
	cin>>n>>p;
	int flag=0,ans=0;
	for(int i=1;;i++)
	{
		if(n-i*p<i) break;
		if(getnum(n-i*p)>i) continue;
		ans=i;
		flag=1;
		break;
	}
	if(flag) cout<<ans<<endl;
	else puts("-1");
	return 0;
}

