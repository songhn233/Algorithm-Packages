#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1050;
int T,n,m,fa[maxn];
int get(int x){if(x!=fa[x]) fa[x]=get(fa[x]); return fa[x];}
void merge(int x,int y)
{
	x=get(x),y=get(y);
	if(x==y) return ;
	fa[x]=y;
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=m;i++)
		{
			int x,y;
			cin>>x>>y;
			merge(x,y);
		}
		int ans=0;
		for(int i=1;i<=n;i++) if(fa[i]==i) ans++;
		cout<<ans<<endl;
	}
	return 0;
}
