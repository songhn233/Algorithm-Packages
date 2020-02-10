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
int mp[15],num;
map<int,int> t;
string s;
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		mp[s[i]-'0']=1;
	}
	printf("int[] arr = new int[]{");
	for(int i=9;i>=0;i--) 
	{
		if(mp[i]) 
		{
			t[i]=num++;
		}
	}
	int tt=0;
	for(int i=9;i>=0;i--)
	{
		if(mp[i])
		{
			if(tt!=num-1) cout<<i<<",";
			else cout<<i<<"};"<<endl;
			tt++;
		}
	}
	printf("int[] index = new int[]{");
	for(int i=0;i<s.size();i++)
	{
		if(i!=(int)s.size()-1) cout<<t[s[i]-'0']<<",";
		else cout<<t[s[i]-'0']<<"};"<<endl;
	}
	return 0;
}

