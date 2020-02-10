#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int T;
int a1,a2,a3,b1,b2,b3;
int n1,n2,n3,t1,t2,t3;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>a1>>a2>>a3;
		cin>>b1>>b2>>b3;
		n3=(a3+b3)%60;
		t3=(a3+b3)/60;
		n2=(a2+b2+t3)%60;
		t2=(a2+b2+t3)/60;
		n1=a1+b1+t2;
		cout<<n1<<" "<<n2<<" "<<n3<<endl;
	}
	return 0;
}
