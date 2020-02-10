#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
using namespace std;
ll T,n,m;
ll mp[20],s[20];
int main()
{
	cin>>T;
	/*mp[1]=10;mp[2]=4;mp[3]=4,mp[4]=2,mp[5]=1,mp[6]=1,mp[7]=4,mp[8]=4,mp[9]=2;
	m[1]=45;m[2]=20,m[3]=20,m[4]=10,m[5]=5,m[6]=6,m[7]=20,m[8]=20,m[9]=10;
	a[1][1]=1,a[1][2]=2,a[1][3]=3,a[1][4]=4,a[1][5]=5,a[1][6]=6,a[1][7]=7,a[1][8]=8,a[1][9]=9;
	a[2][1]=2,a[2][2]=4,a[2][3]=8,a[2][4]=6;
	a[3][1]=3,a[3][2]=9,a[3][3]=7,a[3][4]=1;
	a[4][1]=4,a[4][2]=6;
	a[7][1]=7,a[7][2]=9,a[7][3]=3,a[7][4]=1;
	a[8][1]=8,a[8][2]=4,a[8][3]=2,a[8][4]=6;
	a[9][1]=9,a[9][2]=1;*/
	mp[1]=10,mp[2]=5,mp[3]=10,mp[4]=5,mp[5]=2,mp[6]=5,mp[7]=10,mp[8]=5;mp[9]=10;
	s[1]=45,s[2]=20,s[3]=45,s[4]=20,s[5]=5,s[6]=20,s[7]=45,s[8]=20,s[9]=45;
	while(T--)
	{
		ll ans=0;
		cin>>n>>m;
		if(n<m) cout<<0<<endl;
		else if(n==m) cout<<m%10<<endl;
		else if(m%10==0) cout<<0<<endl;
		else
		{
			ll temp=n/m;
			ll t=m%10;
			if(temp%mp[t]==0)
			{
				ll tt=temp/mp[t];
				ans+=tt*s[t];
			}
			else
			{
				ll tt=temp/mp[t];
				ans+=tt*s[t];
				ll ttt=temp-(temp/mp[t])*mp[t];
				for(int i=1;i<=ttt;i++) ans+=(t*i)%10;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
