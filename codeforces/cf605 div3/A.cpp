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
int T;
ll a,b,c;
int t[]={1,-1,0};
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>a>>b>>c;
		ll ta,tb,tc;
		ll ans=abs(a-b)+abs(a-c)+abs(b-c);
		for(int i=0;i<3;i++)
		{
			ta=a+t[i];
			for(int j=0;j<3;j++)
			{
				tb=b+t[j];
				for(int k=0;k<3;k++)
				{
					tc=c+t[k];
					ans=min(ans,abs(ta-tb)+abs(ta-tc)+abs(tb-tc));
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

