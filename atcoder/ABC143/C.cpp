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
int n;
int main()
{
	cin>>n;
	string s;cin>>s;
	int cnt=1;
	for(int i=0;i<s.size();i++)
	{
		if(i==0) continue;
		if(s[i]==s[i-1]) continue;
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}


