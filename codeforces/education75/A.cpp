#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<set>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
string s;
int T;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>s;
		int cnt=0;
		set<char> ans;
		s+=' ';
		for(int i=1;i<s.size();i++)
		{
			if(s[i]==s[i-1]) cnt++;
			else
			{
				if(cnt%2==0) ans.insert(s[i-1]);
				cnt=0;
			}
		 }
		 for(auto x:ans) cout<<x;
		 puts("");
	}
	return 0;
}

