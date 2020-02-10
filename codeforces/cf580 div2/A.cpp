#include<cstdio>
#include<algorithm>
#include<iostream>
#include<map>

using namespace std;
const int maxn=250;
map<int,bool> mp;
int n,m,a[maxn],b[maxn];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++) cin>>b[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[a[i]+b[j]]==0)
			{
				cout<<a[i]<<" "<<b[j];
				return 0;
			}
		}
	}
} 
