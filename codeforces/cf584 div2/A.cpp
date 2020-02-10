#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int n,a[110],pan[110],flag=0;
int main()
{
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1)
		{
			puts("1");
			return 0;
		}
		if(a[i]==2&&pan[i]==0)
		{
			pan[i]=1;
			ans++;
			for(int i=1;i<=n;i++)
			{
				if(a[i]%2==0&&pan[i]==0)
				{
					pan[i]=1;
					
				}
			}
		}
		
		if(a[i]==3&&pan[i]==0)
		{
			ans++;
			pan[i]=1;
			for(int i=1;i<=n;i++)
			{
				if(a[i]%3==0&&pan[i]==0)
				{
					pan[i]=1;
					
				}
			}
		}
		
		if(a[i]==5&&pan[i]==0)
		{
			ans++;
			pan[i]=1;
			for(int i=1;i<=n;i++)
			{
				if(a[i]%5==0&&pan[i]==0)
				{
					pan[i]=1;
					
				}
			}
		}
		if(a[i]==7&&pan[i]==0)
		{
			ans++;
			pan[i]=1;
			for(int i=1;i<=n;i++)
			{
				if(a[i]%7==0&&pan[i]==0)
				{
					pan[i]=1;
					
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(pan[i]==0)
		{
			ans++;
			pan[i]=1;
			for(int j=1;j<=n;j++) if(a[j]%a[i]==0&&i!=j&&pan[j]==0) pan[j]=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
