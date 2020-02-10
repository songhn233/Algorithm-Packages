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
int a,b,c,d;
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='G'||s[i]=='g') a++;
		if(s[i]=='P'||s[i]=='p') b++;
		if(s[i]=='L'||s[i]=='l') c++;
		if(s[i]=='T'||s[i]=='t') d++;
	}
	while(a||b||c||d)
	{
		if(a) cout<<"G",a--;
		if(b) cout<<"P",b--;
		if(c) cout<<"L",c--;
		if(d) cout<<"T",d--;
	}
	cout<<endl;
	return 0;
}

