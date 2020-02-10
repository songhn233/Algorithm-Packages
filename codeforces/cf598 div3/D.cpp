#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
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
const int maxn=1000010;
ll T,n,k;
string s;
int main()
{
	//ios::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		int pre=-1;
		cin>>s;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='0')
			{
				if(k-(i-pre-1)>=0)
				{
					k-=i-pre-1;
					s[i]='1';
					s[pre+1]='0';
					pre++;
				}
				else
				{
					s[i]='1';
					s[i-k]='0';
					break;
				}
			}
		}
		cout<<s<<endl;
	}
	return 0;
}

