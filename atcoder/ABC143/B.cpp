#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=55;
int n,a[maxn]; 
int main()
{
	cin>>n;
	F(i,1,n) read(a[i]);
	ll sum=0;
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
			sum+=a[i]*a[j];
	}
	cout<<sum<<endl;
	return 0;
}


