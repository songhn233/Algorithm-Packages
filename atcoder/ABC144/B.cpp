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
	int flag=0;
	for(int i=1;i<=9;i++)
	{
		if(n%i==0)
		{
			if(n/i>=1&&n/i<=9)
			{
				puts("Yes");
				flag=1;
				break;
			}
		}
	}
	if(!flag) puts("No");
	return 0;
}

