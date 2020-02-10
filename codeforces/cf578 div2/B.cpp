#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int T,n,m,k,a[105];
int main()
{
	cin>>T;
	while(T--)
	{
		int flag=0;
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=2;i<=n;i++)
		{
			if(a[i]>=a[i-1])
			{
				if(a[i]-a[i-1]<=k) 
				{
					if(a[i]-k<0) m+=a[i-1];
					else m+=(a[i-1]-a[i]+k);
				}
				else
				{
					if(a[i]-a[i-1]-m<=k) m-=(a[i]-a[i-1]-k);
					else
					{
						puts("NO");
						flag=1;
						break;
					}
				}
			}
			else
			{
				if(a[i]-k<0) m+=a[i-1];
				else m+=(a[i-1]-a[i]+k);
			}
		}
		if(!flag) puts("YES");
	}
	return 0;
}
