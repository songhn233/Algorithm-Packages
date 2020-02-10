#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<map>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int q,n;
map<int,int> mp;
int main()
{
	cin>>q;
	while(q--)
	{
		cin>>n;
		mp.clear();
		for(int i=1;i<=n;i++)
		{
			int x;cin>>x;
			mp[x]++;
		}
		for(int i=1;i<=1024;i*=2)
		{
			while(mp[i]>=2)
			{
				mp[i*2]++;
				mp[i]-=2;
			}
		}
		if(mp[2048]>=1) puts("YES");
		else puts("NO");
	}
	return 0;
}
