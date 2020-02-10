#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=150;
ll q;
ll n,k,a[maxn];
int main()
{
	cin>>q;
	while(q--)
	{
		ll minx=0,maxx=inf;
		cin>>n>>k;
		for(int i=1;i<=n;i++) 
		{
			cin>>a[i];
			minx=max(minx,max(a[i]-k,0ll));
			maxx=min(maxx,a[i]+k);
		}
		if(maxx<minx) puts("-1");
		else cout<<maxx<<endl;
	}
	return 0;
}
