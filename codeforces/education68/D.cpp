#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int T,n,k;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		if(k%3==0)
		{
			n%=(k+1);
			if(n%3==0&&n!=k) puts("Bob");
			else puts("Alice");
		}
		else if(n%3==0) puts("Bob");
		else puts("Alice");
	}
	return 0;
}
