#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int t[20];
int l,r;
int main()
{
	cin>>l>>r;
	int pan=0;
	for(int i=l;i<=r;i++)
	{
		int temp=i;
		for(int j=0;j<10;j++) t[j]=0;
		while(temp)
		{
			t[temp%10]++;
			temp/=10;
		}
		int flag=0;
		for(int j=0;j<10;j++) if(t[j]>1) flag=1;
		if(!flag)
		{
			cout<<i<<endl;
			pan=1;
			break;
		}
	}
	if(!pan) puts("-1");
	return 0;
}
