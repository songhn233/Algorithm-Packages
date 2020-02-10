#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int a; 
int main()
{
	cin>>a;
	int flag=0;
	for(int i=a;;i++)
	{
		if(flag) break;
		int temp=i,res=0;
		while(temp)
		{
			res+=temp%10;
			temp/=10;
		}
		if(res%4==0)
		{
			flag=1;
			cout<<i<<endl;
		}
	}
	return 0;
}
