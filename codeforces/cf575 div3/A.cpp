#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
long long a,b,c,ans;
int q;
int main()
{
	cin>>q;
	while(q--)
	{
		cin>>a>>b>>c;
		cout<<(a+b+c)/2<<endl;
	}
	return 0;
}