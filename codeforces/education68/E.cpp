#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define PLL pair<ll,ll>
using namespace std;
const int maxd=10002;
const int maxn=5050;
inline ll read()
{
	ll x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
ll n;
ll ans=0,c[maxd];
vector<PLL> Y[maxd],X[maxd];
vector<ll> cur[maxd];
int lowbit(ll x){return x&-x;}
void add(ll x,ll p)
{
	while(x<=maxd)
	{
		c[x]+=p;
		x+=lowbit(x);
	}
}
ll query(ll x)
{
	ll res=0;
	while(x)
	{
		res+=c[x];
		x-=lowbit(x);
	}
	return res;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		int x1,y1,x2,y2;
		x1=read(),y1=read(),x2=read(),y2=read();
		x1+=5001,y1+=5001,x2+=5001,y2+=5001;
		if(y1>y2) swap(y1,y2);
		if(x1>x2) swap(x1,x2);
		if(y1==y2) Y[y1].push_back(make_pair(x1,x2));
		else X[x1].push_back(make_pair(y1,y2));
	}
	for(int i=1;i<maxd;i++)
	{
		for(auto d1:Y[i])
		{
			memset(c,0,sizeof(c));
			for(int j=1;j<maxd;j++) cur[j].clear();
			for(int j=d1.first;j<=d1.second;j++)
			{
				for(auto x1:X[j])
				{
					if(x1.first<=i&&x1.second>i) 
					{
						cur[x1.second].push_back(j);
						add(j,1);
					}
				}
			}
			for(int j=i+1;j<maxd;j++)
			{
				for(auto d2:Y[j])
				{
					ll res=query(d2.second)-query(d2.first-1);
					ans+=res*(res-1)/2;
				}
				for(auto temp:cur[j]) add(temp,-1);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
