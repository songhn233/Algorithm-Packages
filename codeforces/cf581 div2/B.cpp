#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int n,l,r;
int main()
{
	cin>>n>>l>>r;
	int ans=0;
	int temp=1;
	for(int i=1;i<=l;i++)
	{
		ans+=temp;
		temp*=2;
	}
	for(int i=l+1;i<=n;i++) ans+=1;
	cout<<ans<<" ";
	ans=0;temp=1;
	for(int i=1;i<=r;i++)
	{
		ans+=temp;
		temp*=2;
	}
	temp/=2;
	for(int i=r+1;i<=n;i++) ans+=temp;
	cout<<ans<<" ";
	return 0;
}
