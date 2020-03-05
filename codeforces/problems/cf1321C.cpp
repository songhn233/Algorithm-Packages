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
string s;
int main()
{
	cin>>n;
	cin>>s;
	int flag=1;
	int ans=0;
	while(flag)
	{
		flag=0;
		int temp=0;
		for(int i=25;i>=0;i--)
		{
			if(temp) break;
			for(int j=0;j<s.size();j++)
			{
				if(s[j]!='a'+i) continue;
				if(j-1>=0)
				{
					if(s[j]-s[j-1]==1)
					{
						ans++;
						s.erase(j,1);
						temp=1;flag=1;
						break;
					}
				}
				if(j+1<s.size())
				{
					if(s[j]-s[j+1]==1)
					{
						ans++;
						s.erase(j,1);
						temp=1;flag=1;
						break;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

