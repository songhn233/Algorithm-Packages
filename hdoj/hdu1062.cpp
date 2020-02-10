#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<sstream>
using namespace std;
const int maxn=1050;
int T,top;
char sta[maxn],ch;
int main()
{
	cin>>T;getchar();
	while(T--)
	{
		while(ch=getchar())
		{
			if(ch==EOF||ch=='\n'||ch==' ')
			{
				while(top) cout<<sta[top--];
				if(ch==' ') cout<<' ';
				else break;
			}
			else sta[++top]=ch;
		}
		puts("");
	}
	return 0;
}
