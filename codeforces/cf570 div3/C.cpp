#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
ll q;
ll k,n,a,b;

int main()
{
	cin>>q;
	while(q--)
	{
		cin>>k>>n>>a>>b;
		if(n*b>=k) puts("-1");
		else
		{
			ll ans=(k-n*b)/(a-b);
			if(ans*(a-b)==(k-n*b)) ans--;
			cout<<min(ans,n)<<endl;
		}
	}
	return 0;
}
