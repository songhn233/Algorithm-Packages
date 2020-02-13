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
const int maxn=500050;
string s;
ll a[maxn],cnt,num; 
ll ans[maxn];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9') a[++num]=s[i]-'0';
		else cnt++;
	}
	cnt++;
	sort(a+1,a+num+1,cmp);
	ll base=1;
	for(int i=1;i<=num;i++)
	{
		if(cnt==1&&i!=1) base*=10;
		else if(i%cnt==1&&i!=1) base*=10;
		
		if(i%cnt==0) ans[cnt]+=base*a[i];
		else ans[i%cnt]+=base*a[i];
	}
	ll res=0;
	for(int i=1;i<=cnt;i++) res+=ans[i];
	cout<<res<<endl;
	return 0;
}

