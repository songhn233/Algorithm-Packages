#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100050;
int a[maxn],b[maxn],t[maxn],n;
int main()
{
	cin>>n;
	for(int i=1;i<n;i++) cin>>a[i];
	for(int i=1;i<n;i++) cin>>b[i];
	int flag=0,pan=0;
	for(int p=0;p<=3;p++)
	{
		int flag=1;
		t[1]=p;
		for(int i=2;i<=n;i++)
		{
			t[i]=a[i-1]+b[i-1]-t[i-1];
			if(a[i-1]!=(t[i-1]|t[i])||b[i-1]!=(t[i-1]&t[i])) 
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			puts("YES");
			for(int i=1;i<=n;i++) cout<<t[i]<<" ";
			puts("");
			pan=1;
			break;
		}
	}
	if(!pan) puts("NO");
	return 0;
}
