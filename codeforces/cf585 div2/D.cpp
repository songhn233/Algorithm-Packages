#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=200050;
int n;
char s[maxn];
int c1,c2,s1,s2;
int main()
{
	cin>>n;
	cin>>(s+1);
	
	for(int i=1;i<=n/2;i++)
	{
		if(s[i]=='?') c1++;
		else s1+=s[i]-'0';
	}
	
	for(int i=(n/2)+1;i<=n;i++)
	{
		if(s[i]=='?') c2++;
		else s2+=s[i]-'0';
	}
	if(c1==0&&c2==0)
	{
		if(s1==s2) puts("Bicarp");
		else puts("Monocarp");
	}
	else if(c1==0&&c2)
	{
		int d=s1-s2;
		if(d==(c2/2)*9) puts("Bicarp");
		else puts("Monocarp");
	}
	else if(c1&&c2==0)
	{
		int d=s2-s1;
		if(d==(c1/2)*9) puts("Bicarp");
		else puts("Monocarp");
	}
	else
	{
		if(c1>c2)
		{
			swap(c1,c2);
			swap(s1,s2);
		}
		int d=s1-s2;
		if(d==(c2-c1)/2*9) puts("Bicarp");
		else puts("Monocarp");
	}
	return 0;
}
