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
map<string,bool> mp;
int main()
{
	cin>>s;
	int n=s.size();
	cout<<n<<endl;
	int ans=1;
	for(int i=0;i<n;i++)
	{
		string temp="";
		for(int j=0;j<n;j++) if(j!=i) temp+=s[j];
		mp[temp]=true;
	}
	ans+=mp.size();
	mp.clear();
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			string temp="";
			for(int k=0;k<n;k++) if(k!=i&&k!=j) temp+=s[k];
			mp[temp]=true;
		}
	}
	ans+=mp.size();
	mp.clear();
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				string temp="";
				for(int t=0;t<n;t++) if(t!=i&&t!=j&&t!=k) temp+=s[t];
				mp[temp]=true;
			}
		}
	}
	ans+=mp.size();
	mp.clear();
	cout<<ans<<endl;
	return 0;
}
