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
int T,n;
map<string,int> mp;
string s[15];
int main()
{
	cin>>T;
	while(T--)
	{
		mp.clear();
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i];
			mp[s[i]]++;
		}
		for(int i=1;i<=n;i++)
		{
			if(mp[s[i]]<=1) continue;
			int flag=0;
			for(int j=0;j<s[i].size();j++)
			{
				if(flag) break;
				for(int k=0;k<10;k++)
				{
					string temp=s[i];
					temp[j]='0'+k;
					if(!mp[temp])
					{
						ans++;
						mp[s[i]]--;
						s[i]=temp;
						mp[s[i]]++;
						flag=1;
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++) cout<<s[i]<<endl;
	}
	return 0;
}

