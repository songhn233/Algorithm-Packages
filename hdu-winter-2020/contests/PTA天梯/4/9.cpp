#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define mst(a,b) memset((a),(b),sizeof(a))
#define PII pair<int,int>
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int maxn=10010;
int l,r;
map<int,bool> vis,mp;
int calc_prime(int n)
{
	for(int i=2;i<=n/i;i++)
	{
		if(n%i==0) return 0;
	}
	return 1;
}
int main()
{
	cin>>l>>r;
	int pan=0;
	for(int i=l;i<=r;i++)
	{
		int t=i,tt=0;
		while(t)
		{
			tt+=(t%10)*(t%10);
			t/=10;
		}
		vis[tt]=true;
	}
	for(int i=l;i<=r;i++)
	{
		int prime=1;
		if(vis[i]) continue;
		prime=calc_prime(i);
		
		mp.clear();
		int t=i,tt=0;
		int cnt=0;
		mp[i]=true;
		while(t)
		{
			tt+=(t%10)*(t%10);
			t/=10;
		}
		if(mp[tt]) continue;
		else mp[tt]=true;
		cnt=1;
		while(tt!=1)
		{
			int a=tt,b=0;
			while(a)
			{
				b+=(a%10)*(a%10);
				a/=10;
			}
			tt=b;
			if(mp[tt]) break;
			mp[tt]=true;
			cnt++;
		}
		if(tt==1)
		{
			pan=1;
			if(prime) cout<<i<<" "<<cnt*2<<endl;
			else cout<<i<<" "<<cnt<<endl;
		}
	}
	if(!pan) puts("SAD");
	return 0;
}
