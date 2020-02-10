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
int n,k,s1[maxn],s2[maxn];
string s;
int main()
{
	cin>>n>>k;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0') s1[i]=1;
		else s2[i]=1;
	}
	for(int i=1;i<n;i++) s1[i]+=s1[i-1],s2[i]+=s2[i-1];
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int temp=min(s1[i],s2[i]);
		if(temp<=k) ans=max(ans,i+1);
		else
		{
			int l=0,r=i;
			while(l<r)
			{
				int mid=l+r>>1;
				if(min(s1[i]-s1[mid],s2[i]-s2[mid])<=k) r=mid;
				else l=mid+1;
			}
			if(min(s1[i]-s1[l+1],s2[i]-s2[l+1])<=k)
			{
				ans=max(ans,i-l);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

