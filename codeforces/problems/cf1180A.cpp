#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
int n;
int main()
{
	cin>>n;
	n=2*n-1;
	int temp=(n+1)*(n+1)/4;
	int ans=temp*2-n;
	cout<<ans<<endl;
	return 0;
}
