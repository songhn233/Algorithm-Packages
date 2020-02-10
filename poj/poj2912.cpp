#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=2050;
int n,m,fa[maxn],d[maxn];
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
struct node{
	int l,r,id;
}q[maxn];
void merge(int x,int y,int val)
{
	int a=get(x),b=get(y);
	fa[a]=b;
	if(val==3) d[a]=d[y]-d[x];
	if(val==1) d[a]=d[y]-d[x]-1;
	if(val==2) d[a]=d[y]-d[x]-2;
}
int main()
{
	while(cin>>n>>m)
	{
		int res=0,ans=0,cnt=0;
		for(int i=1;i<=m;i++)
		{
			char c;
			scanf("%d%c%d",&q[i].l,&c,&q[i].r);
			if(c=='=') q[i].id=3;
			else if(c=='<') q[i].id=1;
			else q[i].id=2;
		}
		for(int p=0;p<n;p++)
		{
			int flag=0;
			for(int i=0;i<n;i++) fa[i]=i,d[i]=0;
			for(int i=1;i<=m;i++)
			{
				if(q[i].l==p||q[i].r==p) continue;
				int x=q[i].l,y=q[i].r,pan=q[i].id;
				int a=get(x),b=get(y);
				if(a==b)
				{
					if(pan==3)
					{
						if(((d[y]-d[x])%3+3)%3!=0){flag=1;res=max(res,i);break;}
					}
					else if(pan==1)
					{
						if(((d[y]-d[x])%3+3)%3!=1){flag=1;res=max(res,i);break;}
					}
					else if(((d[y]-d[x])%3+3)%3!=2){flag=1;res=max(res,i);break;}
				}
				else merge(x,y,pan);
			}
			if(!flag)
			{
				ans=p;
				cnt++;
			}
		}
		if(cnt>=2) puts("Can not determine");
		else if(cnt==0) puts("Impossible");
		else printf("Player %d can be determined to be the judge after %d lines\n",ans,res);
	}
	return 0;
}

