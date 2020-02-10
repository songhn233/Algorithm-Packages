#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1050;
int n,m,fa[maxn];
int get(int x){if(x!=fa[x]) fa[x]=get(fa[x]); return fa[x];}
int main()
{
	while(cin>>n>>m)
	{
		if(n==0) break;
		for(int i=1;i<=n;i++) fa[i]=i;
		while(m--)
		{
			int x,y;cin>>x>>y;
			x=get(x),y=get(y);
			if(x==y) continue;
			else fa[x]=y;
		}
		int ans=0;
		for(int i=1;i<=n;i++) if(fa[i]==i) ans++;
		cout<<ans-1<<endl;
	}
	return 0;
}
