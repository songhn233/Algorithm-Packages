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
int n,k;
string s;
int main()
{
	cin>>n>>k;
	cin>>s;
	if(n==1)
	{
		if(k>=1) puts("0");
		else cout<<s<<endl;
	}
	else
	{
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			if(s[0]>'1'&&k>=1)
			{
				k--;
				s[0]='1';
			}
			if(k==0) break;
		}
		else
		{
			if(s[i]>'0'&&k>=1)
			{
				s[i]='0';
				k--;
			}
			if(k==0) break;
		}
	}
	cout<<s<<endl;
	}
	return 0;
}
