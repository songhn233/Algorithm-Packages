#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=40050;
ll n,p;
ll phi[maxn],vis[maxn],prime[maxn],num;
void calc_prime(int n)
{
	phi[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i]) prime[++num]=i,phi[i]=i-1;
		for(int j=1;j<=num&&prime[j]*i<=n;j++)
		{
			vis[prime[j]*i]=1;
			if(i%prime[j]==0)
			{
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
}
int main()
{
	cin>>n;
	calc_prime(n);
	ll ans=3;
	for(int i=2;i<=n-1;i++) ans+=2*phi[i];
	if(n==1) puts("0");
	else cout<<ans<<endl;
	return 0;
}
