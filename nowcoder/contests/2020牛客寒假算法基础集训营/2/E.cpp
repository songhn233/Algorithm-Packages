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
int n;
vector<int> a;
int main()
{
	cin>>n;
	int ans=0;
	for(int i=1;i<=n/i;i++) a.push_back(i*i);
	for(int i=0;i<a.size();i++)
	{
		int m=a[i];
		for(int j=1;j<=m/j;j++)
		{
			if(m%j==0) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

