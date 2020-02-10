#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=200050;
string s,t;
int pre[maxn],nex[maxn];
int main()
{
	cin>>s>>t;
	int pos=0;
	int n=s.size(),m=t.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]==t[pos]) 
		{
			pre[pos]=i;
			pos++;
		}
		if(pos>=m) break;
	}
	pos=m-1;
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]==t[pos])
		{
			nex[pos]=i;
			pos--;
		}
		if(pos<0) break;
	}
	int ans=0;
	ans=max(ans,nex[0]);
	ans=max(ans,n-pre[m-1]-1);
	for(int i=1;i<m;i++) ans=max(ans,nex[i]-pre[i-1]-1);
	cout<<ans<<endl;
	return 0;
}
