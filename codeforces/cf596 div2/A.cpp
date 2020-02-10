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
int a,b;
int main()
{
	cin>>a>>b;
	if(a==9&&b==1) cout<<9<<" "<<10<<endl;
	else if(a+1==b) cout<<a<<" "<<b<<endl;
	else if(a==b) cout<<a*10+1<<" "<<b*10+2<<endl;
	else puts("-1"); 
	return 0;
}

