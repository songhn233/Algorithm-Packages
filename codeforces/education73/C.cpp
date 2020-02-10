#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int q;
int c,m,x;
int main()
{
	cin>>q;
	while(q--)
	{
		int ans=0;
		cin>>c>>m>>x;
		int t1=min(c,m);
		int t2=(c+m+x)/3;
		cout<<min(t1,t2)<<endl; 
	}
	return 0;
}
