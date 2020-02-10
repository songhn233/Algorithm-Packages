#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=105;
int n;
int main()
{
	while(~scanf("%d",&n))
	{
		if(n==0) break;
		int last=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			int x;cin>>x;
			if(x>last)
			{
				ans+=(x-last)*6+5;
			}
			else ans+=(last-x)*4+5;
			
			last=x;
		}
		cout<<ans<<endl;
	}
	return 0;
}
