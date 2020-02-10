#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100050;
int n,k,a[maxn];
int main()
{
	cin>>n>>k;
	int t1=1,t2=n;
	for(int i=1;i<=n;i++)
	{
		if(i&1) a[i]=t1++;
		else a[i]=t2--;
	}
	if(k&1) sort(a+k,a+n+1);
	else sort(a+k,a+n+1,greater<int>());
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	puts("");
	return 0;
}
