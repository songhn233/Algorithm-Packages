#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=2010;
int q,n,k,a[maxn];
int main()
{
	cin>>q;
	while(q--)
	{
		memset(a,0,sizeof(a));
		cin>>n>>k;
		string s;cin>>s;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='R') a[i+1]=0;
			if(s[i]=='G') a[i+1]=1;
			if(s[i]=='B') a[i+1]=2;
		}
		int ans=k;
		for(int i=1;i<=n-k+1;i++)
		{
			int x=0,y=0,z=0;
			for(int j=0;j<k;j++)
			{
				if(a[i+j]!=j%3) x++;
				if(a[i+j]!=(j+1)%3) y++;
				if(a[i+j]!=(j+2)%3) z++;
			}
			ans=min(min(ans,x),min(y,z));
		}
		cout<<ans<<endl;
	}
	return 0;
}
