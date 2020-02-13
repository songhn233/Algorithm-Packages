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
string s;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>s;
		int cnt=0,st=-1,ed=-1;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='1')
			{
				if(st==-1)
				{
					st=ed=i;
				}
				else ed=i;
				cnt++;
			}
		}
		if(st==-1) puts("0");
		else
		{
			cout<<ed-st+1-cnt<<endl;
		}
	}
	return 0;
}

