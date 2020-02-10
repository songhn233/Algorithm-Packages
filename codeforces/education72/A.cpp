#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
ll T,a,b,c;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>a>>b>>c;
		if(a+c<=b) puts("0");
		else if(c==0) puts("1");
		else
		{
			ll t;
			if(c+b-a<0) t=0;
			else t=((c+b-a)/2)+1;
			
			cout<<c-t+1<<endl;
		}
	}
	return 0;
}

