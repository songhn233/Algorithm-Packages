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
const int inf=0x3f3f3f3f;
const ll p1=1222827239;
const ll p2=1e9+7;
const ll p3=2181271;
int T;
ll a,b,c,d,e,f,g;
ll p[]={1222827239,1000000007,2181271,122777,51787,9209};
ll ksm(ll a,ll b,int i)
{
	ll res=1%p[i];
	while(b)
	{
		if(b&1) res=(res*a)%p[i];
		a=(a*a)%p[i];
		b>>=1;
	}
	return res;
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>a>>b>>c>>d>>e>>f>>g;
		ll t1,t2,t3;
		int flag=1;
		for(int i=0;i<6;i++)
		{
			
		if(a<0) 
		{
			t1=ksm(-a,d,i);
			if(d%2==1) t1=(p[i]-t1)%p[i];
		}
		else if(a==0) t1=0;
		else t1=ksm(a,d,i);
		
		if(b<0) 
		{
			t2=ksm(-b,e,i);
			if(e%2==1) t2=(p[i]-t2)%p[i];
		}
		else if(b==0) t2=0;
		else t2=ksm(b,e,i);
		
		if(c<0) 
		{
			t3=ksm(-c,f,i);
			if(f%2==1) t3=(p[i]-t3)%p[i];
		}
		else if(c==0) t3=0;
		else t3=ksm(c,f,i);
		if(((t1+t2+t3)%p[i]+p[i])%p[i]==(g%p[i]+p[i])%p[i]) continue;
		else flag=0;
		}
		if(flag==0) puts("No");
		else puts("Yes");
	}
	
	return 0;
}

