#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
int n,a[15];
int main()
{
	cin>>n;
	while(n--)
	{
		char c;cin>>c;
		if(c=='L')
		{
			for(int i=0;i<10;i++)
			{
				if(a[i]==1) continue;
				a[i]=1;
				break;
			}
		}
		else if(c=='R')
		{
			for(int i=9;i>=0;i--)
			{
				if(a[i]==1) continue;
				a[i]=1;
				break;
			}
		}
		else
		{
			int t=c-48;
			a[t]=0;
		}
	}
	for(int i=0;i<10;i++) cout<<a[i];
	return 0;
}
