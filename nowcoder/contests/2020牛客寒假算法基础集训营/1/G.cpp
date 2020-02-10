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
int n,k;
vector<int> a[30];
string s;
int main()
{
	cin>>n>>k;
	cin>>s;
	int ans=inf;
	if(k==1) puts("1");
	else
	{
		for(int i=0;i<s.size();i++)
	{
		if((int)a[s[i]-'a'].size()>=k-1)
		{
			ans=min(ans,i-a[s[i]-'a'][0]+1);
			a[s[i]-'a'].erase(a[s[i]-'a'].begin());
			a[s[i]-'a'].push_back(i);
		}
		else a[s[i]-'a'].push_back(i);
	}
	if(ans==inf) puts("-1");
	else cout<<ans<<endl;
	}
	
	return 0;
}

