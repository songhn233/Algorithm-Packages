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
int main()
{
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='6')
		{
			int flag=0,j;
			for(j=i;j<s.size();j++)
			{
				if(s[j]!='6') 
				{
					break;
				}
			}
			j--;
			if(j-i+1>9) s.replace(i,j-i+1,"27");
			else if(j-i+1>3) s.replace(i,j-i+1,"9");
		}
	}
	cout<<s<<endl;
	return 0;
}

