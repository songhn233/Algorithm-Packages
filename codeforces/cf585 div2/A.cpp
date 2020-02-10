#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int a1,a2,k1,k2,n;
int main()
{
	cin>>a1>>a2>>k1>>k2>>n;
	int temp=a1*(k1-1)+a2*(k2-1);
	if(n>=temp) cout<<n-temp<<" ";
	else cout<<0<<" ";
	
	if(k1>k2)
	{
		swap(a1,a2);
		swap(k1,k2);
	}
	if(n>=a1*k1) cout<<a1+((n-a1*k1)/k2)<<endl;
	else cout<<n/k1<<endl;
	return 0;
}
