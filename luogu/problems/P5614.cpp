#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int N=10;
int a[N],b[N],c[N];
int n,m;
int main()
{
	cin>>n>>m;
	ll ans=0;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
	for(int x=1;x<=m;x++)
	{
		for(int y=1;y<=m;y++)
		{
			int temp=abs(x-a[1])^abs(y-b[1])^9;
			int z1=c[1]-temp,z2=c[1]+temp;
			int p1,p2;p1=p2=1;
			if(z1>m||z1<1) p1=0;
			if(z2>m||z2<1) p2=0;
			if(temp==0) p1=1,p2=0;
			for(int i=2;i<=n;i++)
			{
				if((abs(x-a[i])^abs(y-b[i])^abs(z1-c[i])^9)==0) p1&=1; else p1=0;
				if((abs(x-a[i])^abs(y-b[i])^abs(z2-c[i])^9)==0) p2&=1; else p2=0;
			}
			ans+=(p1+p2);
		}
	}
	cout<<ans<<endl;
	return 0;
}
