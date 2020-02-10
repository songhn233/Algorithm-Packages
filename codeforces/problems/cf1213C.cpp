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
ll mp[20][20],size[20],sum[20];
ll q,n,m;
int main()
{
	for(int i=1;i<=9;i++)
	{
		size[i]=1;
		mp[i][1]=i;
		ll temp=i+i;
		while(temp%10!=i)
		{
			mp[i][++size[i]]=temp%10;
			temp+=i;
		}
	}
	for(int i=1;i<=9;i++) 
	{
		for(int j=1;j<=size[i];j++)
			sum[i]+=mp[i][j];
	}
	/*for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=size[i];j++) cout<<mp[i][j]<<" ";
		cout<<endl;
	}*/
	cin>>q;
	while(q--)
	{
		cin>>n>>m;
		if(n<m) puts("0");
		else if(n==m) cout<<m%10<<endl;
		else if(m%10==0) puts("0");
		else
		{
			ll a=n/m;
			m=m%10;
			ll t1=a/size[m];
			ll ans=0;
			ans+=t1*sum[m];
			if(t1*size[m]!=a)
			{
				for(ll i=t1*size[m]+1;i<=a;i++)
				{
					ans+=mp[m][(i-(t1*size[m]))];
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
