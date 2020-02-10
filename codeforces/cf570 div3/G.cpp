#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=200050;
int q,n;
struct node{
	int val,p;
	bool operator<(const node t) const{
		return p<t.p;
	}
}a[maxn];
bool cmp(node a,node b)
{
	if(a.val==b.val) return a.p<b.p;
	return a.val<b.val;
}
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
int main()
{
	q=read();
	while(q--)
	{
		n=read();
		for(int i=1;i<=n;i++) a[i].val=a[i].p=0;
		for(int i=1;i<=n;i++)
		{
			int x,y;x=read(),y=read();
			a[x].val++;
			if(y==1) a[x].p++;
		}
		sort(a+1,a+n+1,cmp);
		int ans=0,t=inf,ans2=0;
		priority_queue<node>q;
		while(!q.empty()) q.pop();
		for(int i=n;i>=1;)
		{
			t--;
			if(t==0) break;
			if(a[i].val==0) break;
			t=min(t,a[i].val);
			int j=i;
			while(a[j].val>=t)
			{
				q.push(a[j]);
				j--;
			}
			node temp=q.top();q.pop();
			ans+=t;ans2+=temp.p;
			i=j;
		}
		while(t>=1)
		{
			if(q.empty()) break;
			node temp=q.top();q.pop();
			ans+=t,ans2+=temp.p;
			t--;
		}
		cout<<ans<<" "<<ans2<<endl;
	}
	return 0;
}
