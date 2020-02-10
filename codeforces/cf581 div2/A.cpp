#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
string s;
int a[105];
int main()
{
	cin>>s;
	int n=s.size();
	for(int i=0;i<s.size();i++) a[i+1]=s[i]-'0';
	int flag=0;
	for(int i=2;i<=n;i++) if(a[i]==1) flag=1;
	int ans=0;
	if(flag==1)
	{
		for(int i=n;i>=1;i-=2)
		{
			ans++;
		}
	}
	else
	{
		for(int i=n;i>=2;i-=2)
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
