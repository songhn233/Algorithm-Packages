#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
ll a,b;
int main()
{
	cin>>a>>b;
	if(a==b) puts("0");
	else
	{
		for(ll i=60;i>=0;i--)
		{
			if((a&(1ll<<i))==(b&(1ll<<i))) continue;
			else
			{
				cout<<((1ll<<(i+1))-1)<<endl;
				break;
			}
		}
	}
	return 0;
}
