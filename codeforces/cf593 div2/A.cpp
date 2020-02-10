#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int T;
int a,b,c;
int main()
{
	cin>>T;
	while(T--)
	{
		int ans=0;
		cin>>a>>b>>c;
		int t1=c/2;
		if(b-t1>=0)
		{
			b-=t1;
			ans+=t1;
			int t2=b/2;
			if(a-t2>=0) ans+=t2;
			else ans+=a;
		}
		else ans+=b;
		cout<<ans*3<<endl;
	}
	return 0;
}

