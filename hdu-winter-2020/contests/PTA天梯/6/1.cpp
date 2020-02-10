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
int x,t;
map<int,int> mp;
int main()
{
	cin>>x>>t;
	int ans=0;
	int i;
	for(i=x;;i++)
	{
		mp.clear();
		int temp=i;
		mp[temp%10]=1;mp[(temp/10)%10]=1;
		mp[(temp/100)%10]=1;mp[(temp/1000)%10]=1;
		if(mp.size()==t)
		{
			break;
		}
		ans++;
	}
	printf("%d %04d\n",ans,i);
	return 0;
}
