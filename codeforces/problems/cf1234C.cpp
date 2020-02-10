#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=200010;
int T,n,a[2][maxn];
struct node{
	int v,nex;
}e[10*maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n;
		string s;cin>>s;
		for(int i=0;i<s.size();i++)
		{
			int t=s[i]-'0';
			if(t==1||t==2) a[0][i+1]=1;
			else a[0][i+1]=2;
		}
		cin>>s;
		for(int i=0;i<s.size();i++)
		{
			int t=s[i]-'0';
			if(t==1||t==2) a[1][i+1]=1;
			else a[1][i+1]=2;
		}
		int temp=0,flag=0;
		for(int i=1;i<=n;i++)
		{
			if(a[temp][i]==1) continue;
			if(a[(temp+1)%2][i]==1)
			{
				flag=1;
				break;
			}
			temp=(temp+1)%2;
		}
		if(flag||temp==0) puts("NO");
		else puts("YES");
	}
	return 0;
}
