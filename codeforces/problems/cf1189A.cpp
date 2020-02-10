#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdio>
using namespace std;
int n;
string s;
int main()
{
	cin>>n;
	cin>>s;
	int t=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1') t++;
	}
	if(t!=n-t) 
	{
		puts("1");
		cout<<s<<endl;
	}
	else
	{
		puts("2");
		cout<<s[0]<<" ";
		for(int i=1;i<n;i++) cout<<s[i];
		puts("");
	}
	return 0;
}
