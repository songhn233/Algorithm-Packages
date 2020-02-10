#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<sstream>
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
int T,num,flag[1050];
string s;
vector<string> t;
bool calc_al(char s)
{
	if(s>='a'&&s<='z') return true;
	if(s>='A'&&s<='Z') return true;
	return false;
}
int main()
{
	cin>>T;getchar();
	while(T--)
	{
		num=0;
		memset(flag,0,sizeof(flag));
		getline(cin,s);
		stringstream sin(s);
		string x;
		while(sin>>x) t.push_back(x);
		cout<<s<<endl;
		cout<<"AI: ";
		for(int i=0;i<t.size();i++)
		{
			for(int j=0;j<t[i].size();j++)
			{
				if(t[i][j]=='i'||t[i][j]=='I') continue;
				else t[i][j]=tolower(t[i][j]);
			}
			if(!calc_al(t[i][0])) 
			{
				char temp=t[i][0];
				string tt;
				tt.push_back(temp);
				t[i]=t[i].substr(1);
				t.insert(t.begin()+i,tt);
			}
			int len=t[i].size()-1;
			if(!calc_al(t[i][len])) 
			{
				char temp=t[i][len];
				string tt;
				tt.push_back(temp);
				t[i]=t[i].substr(0,len);
				t.insert(t.begin()+i+1,tt);
			}
		}
		for(int i=0;i<t.size();i++)
		{
			string temp;
			if(t[i]=="you")
			{
				if(i-1>=0)
				{
					if(t[i-1]=="can")
					{
						t[i-1]="I";
						t[i]="can";
					}
					else if(t[i-1]=="could")
					{
						t[i-1]="I";
						t[i]="could";
					}
				}
			}
			if(t[i]=="I"||t[i]=="me") t[i]="you";
			if(t[i]=="?") t[i]="!";
		}
		for(int i=0;i<t.size();i++)
		{
			if(t[i].size()==1)
			{
				char tt=t[i][0];
				if(!calc_al(tt)) cout<<t[i];
			}
			else
			{
				if(i==0) cout<<t[i];
				else cout<<" "<<t[i];
			}
		}
		cout<<endl;
	}
	return 0;
}

