#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int n;
string s;
int a[110],b[110],c[110];
int p[10500];
int main()
{
	int ans=0;
	cin>>n;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	for(int i=0;i<s.size();i++) c[i+1]=s[i]-'0';
	for(int i=1;i<=n;i++) if(c[i]==1) p[0]++;
	ans=p[0];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=b[i]-1;j++) p[j]+=c[i];
		
		for(int j=0;j<=10000;j++) 
		{
			if(b[i]+j>=10010) break;
			if(j%a[i]==0)
			{
				c[i]^=1;
			}
			
			p[b[i]+j]+=c[i];
		}
	}
	for(int i=1;i<=10000;i++) ans=max(ans,p[i]);
	cout<<ans<<endl;
	return 0;
}
