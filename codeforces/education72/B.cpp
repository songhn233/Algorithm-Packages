#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int T;
int n,x;
struct node{
	int d,h;
	bool operator<(const node t) const{
		return d-h>t.d-t.h;
	}
}a[150];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>x;
		int flag=0,maxx=0,mal=0;
		for(int i=1;i<=n;i++) 
		{
			cin>>a[i].d>>a[i].h;
			maxx=max(maxx,a[i].d);
			mal=max(mal,a[i].d-a[i].h);
		}
		if(maxx>=x) puts("1");
		else
		{
			if(mal<=0) puts("-1");
			else
			{
				x-=maxx;
				int ans=x/mal;
				if(ans*mal!=x) ans++;
				cout<<ans+1<<endl;
			}
		}
	}
	return 0;
}
