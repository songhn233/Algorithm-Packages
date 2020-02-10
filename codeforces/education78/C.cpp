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
const int maxn=200050;
int T,n;
int a[maxn];
int main()
{
	cin>>T;
	while(T--)
	{
		read(n);
		int t1,t2;
		t1=t2=0;
		for(int i=1;i<=2*n;i++)
		{
			read(a[i]);
			if(a[i]==1) t1++;
			else t2++;
		}
		map<int,int> mp;
		int t=0;
		for(int i=n+1;i<=2*n;i++)
		{
			if(a[i]==1) t--;
			else t++;
			if(!mp[t]) mp[t]=i-n;
		}
		int temp=t1-t2;
		int ans;
		if(mp[-temp]) ans=mp[-temp];
		else ans=inf;
		for(int i=n;i>=1;i--)
		{
			if(a[i]==1) temp--;
			else temp++;
			if(temp==0) ans=min(ans,n-i+1);
			else if(mp[-temp]) ans=min(ans,n-i+1+mp[-temp]);
		}
		if(t1-t2==0) puts("0");
		else cout<<ans<<endl;
	}
	return 0;
}

