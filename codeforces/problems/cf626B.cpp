#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
string s;
int a,b,c,n;
int main()
{
	cin>>n;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='R') a++;
		else if(s[i]=='G') b++;
		else if(s[i]=='B') c++;
	}
	if(a==0&&b==0) puts("B");
	else if(a==0&&c==0) puts("G");
	else if(b==0&&c==0) puts("R");
	else if(a==0)
	{
		if(b==1&&c==1) puts("R");
		else if(b==1&&c>=2) puts("GR");
		else if(b>=2&&c==1) puts("BR");
		else puts("BGR");
	}
	else if(b==0)
	{
		if(a==1&&c==1) puts("G");
		else if(a==1&&c>=2) puts("GR");
		else if(a>=2&&c==1) puts("BG");
		else puts("BGR");
	}
	else if(c==0)
	{
		if(b==1&&a==1) puts("B");
		else if(b=
		=1&&a>=2) puts("BG");
		else if(b>=2&&a==1) puts("BR");
		else puts("BGR");
	}
	else puts("BGR");
	
	return 0;
}
