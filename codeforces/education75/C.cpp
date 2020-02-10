#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=300050;
int T,a[maxn],t1[maxn],t2[maxn],num1,num2;
int main()
{
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		num1=num2=0;
		string s;
		cin>>s;
		for(int i=0;i<s.size();i++)
		{
			if((s[i]-'0')%2==0) t1[++num1]=s[i]-'0';
			else t2[++num2]=s[i]-'0';
		}
		int p1=1,p2=1;
		int n=0;
		while(p1<=num1&&p2<=num2)
		{
			if(t1[p1]<t2[p2]) a[++n]=t1[p1++];
			else a[++n]=t2[p2++];
		}
		while(p1<=num1) a[++n]=t1[p1++];
		while(p2<=num2) a[++n]=t2[p2++];
		for(int i=1;i<=n;i++) cout<<a[i];
		cout<<endl;
	}
	return 0;
}
