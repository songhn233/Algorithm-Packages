#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int n;
int main()
{
	cin>>n;
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		if((i+j)%2==0) cout<<"B";
		else cout<<"W";
		
		puts("");
	}
		  
	return 0;
}
