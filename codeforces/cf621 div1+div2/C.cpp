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
string s;
ll mp[30],t[30][30],temp[30];
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		temp[s[i]-'a']++;
	}
	ll ans=1;
	for(int i=0;i<26;i++) ans=max(ans,temp[i]);
	for(int i=0;i<26;i++) ans=max(ans,temp[i]*(temp[i]-1)/2);
	int n=(int)s.size()-1;
	for(int i=n;i>=0;i--)
	{
		for(int j=0;j<26;j++) 
		{
			if(s[i]-'a'==j) continue;
			t[s[i]-'a'][j]+=mp[j];
		}
		mp[s[i]-'a']++;
	}
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<26;j++)
			ans=max(ans,t[i][j]);
	}
	cout<<ans<<endl;
	return 0;
}

