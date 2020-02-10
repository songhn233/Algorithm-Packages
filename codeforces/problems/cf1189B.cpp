#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=100050;
int n,a[maxn];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<3) 
	{
		puts("YES");
		for(int i=1;i<=n;i++) cout<<a[i]<<" ";
		puts("");
	}
	else
	{
		if(a[n-2]+a[n-1]<=a[n]) puts("NO");
		else
		{
			puts("YES");
			swap(a[n-1],a[n]);
			for(int i=1;i<=n;i++) cout<<a[i]<<" ";
			puts("");
		}
	}
	return 0;
}
