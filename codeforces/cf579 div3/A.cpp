#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<iostream>
using namespace std;
const int inf=0x3f3f3f3f;
inline int read()
{
    int x=0,t=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*t;
}
int q,n,a[250];
int main()
{
	cin>>q;
	while(q--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		int t=2;
		int flag=1;
		for(int i=a[1]+1;i<=n;i++)
		{
			if(a[t]==i) t++;
			else flag=0;
		}
		for(int i=1;i<=a[1]-1;i++)
		{
			if(a[t]==i) t++;
			else flag=0;
		}
		if(flag) puts("YES");
		else
		{
			flag=1;
			int t=2;
			for(int i=a[1]-1;i>=1;i--)
			{
				if(a[t]==i) t++;
				else flag=0;
			}
			for(int i=n;i>=a[1]+1;i--)
			{
				if(a[t]==i) t++;
				else flag=0;
			}
			if(flag) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
