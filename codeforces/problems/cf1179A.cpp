#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<deque>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=300050;
inline ll read()
{
	ll x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
ll n,Q,a[maxn];
ll t1[maxn],t2[maxn],p[maxn],num=0,cnt=0;
int main()
{
	n=read(),Q=read();
	ll maxx=0;
	for(int i=1;i<=n;i++) 
	{
		a[i]=read();
		maxx=max(maxx,a[i]);
	}
	deque<ll> q;
	while(!q.empty()) q.pop_back();
	for(int i=1;i<=n;i++) q.push_back(a[i]);
	while(q.front()!=maxx)
	{
		ll x=q.front(); q.pop_front();
		ll y=q.front(); q.pop_front();
		t1[++num]=x,t2[num]=y;
		if(x<y) swap(x,y);
		q.push_front(x);
		q.push_back(y);
	}
	for(int i=1;i<=n-1;i++)
	{
		ll x=q.front(); q.pop_front();
		ll y=q.front(); q.pop_front();
		q.push_front(x);
		p[++cnt]=y;
		q.push_back(y);
	}
	while(Q--)
	{
		ll pos;pos=read();
		if(pos<=num) cout<<t1[pos]<<" "<<t2[pos]<<endl;
		else
		{
			pos-=num;
			pos%=(n-1);
			if(pos==0) pos=n-1;
			cout<<maxx<<" "<<p[pos]<<endl;
		}
	}
	return 0;
}
