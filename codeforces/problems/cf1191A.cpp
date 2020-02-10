#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main()
{
	cin>>n;
	int temp=n%4;
	if(temp==1) cout<<0<<" "<<"A"<<endl;
	if(temp==2) cout<<1<<" "<<"B"<<endl;
	if(temp==3) cout<<2<<" "<<"A"<<endl;
	if(temp==0) cout<<1<<" "<<"A"<<endl;
	return 0;
}
