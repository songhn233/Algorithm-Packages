#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
using namespace std;
int n,t1,t2;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		ll x;cin>>x;
		if(x%2==1) t1++;
		else t2++;
	}
	cout<<min(t1,t2)<<endl;
	return 0;
}
