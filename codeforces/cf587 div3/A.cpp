#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int n;
string s;
int main()
{
	cin>>n>>s;
	int ans=0;
	for(int i=0;i<n;i+=2)
	{
		if(s[i]=='a'&&s[i+1]=='a')
		{
			s[i]='a',s[i+1]='b';
			ans++;
		}
		
		if(s[i]=='b'&&s[i+1]=='b')
		{
			s[i]='a';s[i+1]='b';
			ans++;
		}
	}
	cout<<ans<<endl;
	cout<<s<<endl;
	return 0;
}
