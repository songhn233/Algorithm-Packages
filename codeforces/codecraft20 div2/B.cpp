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
const int maxn=5050;
int T,n,res=1;
string s,ans;
char tt[maxn];
char minx;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;cin>>s;
		res=1;
		ans=s;
		for(int i=0;i<n-1;i++)
		{
			string t1=s.substr(0,i+1);
			if(n%2==i%2) reverse(t1.begin(),t1.end());
			string t2=s.substr(i+1);
			string t3=t2+t1;
			if(t3<ans)
			{
				ans=t3;
				res=i+2;
			}
		}
		cout<<ans<<endl<<res<<endl;
	}
	return 0;
}

