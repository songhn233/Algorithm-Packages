#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int T,n;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		int pan=0,p=0;
		for(int i=1;i<=n;i++)
		{
			string s;cin>>s;
			if(s.size()%2==1) pan++;
			int a=0,b=0;
			for(int j=0;j<s.size();j++)
			{
				if(s[j]=='0') a++;
				if(s[j]=='1') b++;
			}
			if(a%2==1&&b%2==1) p++;
		}
		if(p%2==1&&pan==0) cout<<n-1<<endl;
		else cout<<n<<endl;
	}
	return 0;
}
