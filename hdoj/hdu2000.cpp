#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
char a,b,c;
int main()
{
	while(cin>>a>>b>>c)
	{
		if(a>b) swap(a,b);
		if(c<a) swap(a,c),swap(b,c);
		if(c<b) swap(b,c);
		cout<<a<<" "<<b<<" "<<c<<endl;
	}
	return 0;
}
