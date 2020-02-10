#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=1050;
int n,k,a[maxn],ans,tt[maxn],num;
int main()
{
	scanf("%d%d",&n,&k);
	int t=n/2;
	if(t*2!=n) t++;
	for(int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		a[x]++;
	}
	sort(a+1,a+k+1);
	for(int i=1;i<=k;i++)
	{
		if(a[i]==0) continue;
		if(a[i]&1==0)
		{
			int temp=a[i]/2;
			if(temp<=t) 
			{
				t-=temp;
				ans+=a[i];
			}
			else
			{
				ans+=t*2;
				t=0;
				break;
			}
		}
		else
		{
			int temp=a[i]/2;
			if(temp<=t)
			{
				t-=temp;
				ans+=temp*2;
				tt[++num]=i;
			}
			else
			{
				ans+=t*2;
				t=0;
				break;
			}
		}
		if(t==0) break;
	}
	if(t) 
	{
		for(int i=1;i<=num;i++)
		if(t) ans++,t--;
	}
	
	cout<<ans<<endl;
	return 0;
}
