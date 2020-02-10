#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=100050;
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
int n;
int a[maxn];
bool cmp(int x,int y)
{
	return abs(x)<abs(y);
}
int main()
{
	n=read();
	int temp=0,pos=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]>=0) a[i]=-a[i]-1;
		if(a[i]<temp)
		{
			temp=a[i];
			pos=i;
		}
	}
	if(n&1)
	{
		a[pos]=-a[pos]-1;
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
