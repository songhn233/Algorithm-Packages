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
int ans=0;
vector<int> t1,t2;
int main()
{
	cin>>s;
	int n=s.size();
	int l=0,r=n-1;
	while(l<r)
	{
		while(l<r&&s[l]!='(') l++;
		while(l<r&&s[r]!=')') r--;
		if(l<r)
		{
			t1.push_back(l+1);
			t2.push_back(r+1);
		}
		l++,r--;
	}
	if(t1.empty())
	{
		puts("0");
	}
	else
	{
		cout<<"1"<<endl;
		cout<<((int)t1.size())*2<<endl;
		for(int i=0;i<t1.size();i++) cout<<t1[i]<<" ";
		for(int i=(int)t2.size()-1;i>=0;i--) cout<<t2[i]<<" ";
		cout<<endl;
	}
	return 0;
}

