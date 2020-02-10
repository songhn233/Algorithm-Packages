#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=200050;
int n,m,fa[maxn],d[maxn],ans;
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
int get(int x)
{
	if(x!=fa[x])
	{
		int t=get(fa[x]);
		d[x]+=d[fa[x]];
		fa[x]=t;
	} 
	return fa[x];
}
int main()
{
	while(cin>>n>>m)
	{
		ans=0;
		for(int i=0;i<=n;i++) fa[i]=i,d[i]=0;
		while(m--)
		{
			int x,y,z;
			x=read(),y=read(),z=read();
			int a=get(x-1),b=get(y);
			if(a==b)
			{
				if(d[y]-d[x-1]==z) continue;
				else ans++;
			}
			else
			{
				fa[a]=b;
				d[a]=d[y]-d[x-1]-z;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
