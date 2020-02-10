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
string s,t;
map<string,string> mp;
int main()
{
	while(cin>>s)
	{
		if(s=="START") continue;
		if(s=="END") break;
		cin>>t;
		mp[t]=s;
	}
	getchar();
	while(getline(cin,s))
	{
		if(s=="START") continue;
		if(s=="END") break;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]>='a'&&s[i]<='z')
			{
				int temp=i;
				while(s[temp]>='a'&&s[temp]<='z') temp++;
				temp--;
				string t=s.substr(i,temp-i+1);
				if(mp[t]!="") cout<<mp[t];
				else cout<<t;
				i=temp;
			}
			else cout<<s[i];
		}
		printf("\n");
	}
	return 0;
}

