#include<iostream>
#include<algorithm>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int x,y,a,b;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main()
{
	cin>>x>>y>>a>>b;
	int t=gcd(x,y);
	t=x*y/t;
	int l,r;
	if(a%t==0) l=a;
	else l=a/t*t+t;
	
	if(b%t==0) r=b;
	else r=b/t*t;
	
	cout<<(r-l)/t+1<<endl;
	return 0;
}
