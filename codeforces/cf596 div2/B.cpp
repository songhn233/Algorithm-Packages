#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<map>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=200050;
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
int T;
int n,k,d,a[maxn];
map<int,int> mp;
int main()
{
	T=read();
	while(T--)
	{
		int ans=inf;
		int cnt=0;
		mp.clear();
		n=read(),k=read(),d=read();
		for(int i=1;i<=n;i++) a[i]=read();
		int l=1,r=0;
		for(int i=1;i<=d;i++) 
		{
			if(mp[a[i]]==0) cnt++;
			mp[a[i]]++;
		}
		ans=cnt;
		for(int l=1,r=d;r<=n;l++,r++)
		{
			//cout<<cnt<<"--"<<endl;
			ans=min(ans,cnt);
			mp[a[l]]--;
			if(mp[a[l]]==0) cnt--;
			if(mp[a[r+1]]==0) cnt++;
			mp[a[r+1]]++;
			
		}
		cout<<ans<<endl;
	}
	return 0;
}

