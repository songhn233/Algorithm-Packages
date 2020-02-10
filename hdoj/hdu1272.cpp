#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<map>
#define PII pair<int,int>
using namespace std;
const int maxn=100005;
const int N=100000;
int n,m,fa[maxn],num,edge;
int findx(int x){if(x!=fa[x]) fa[x]=findx(fa[x]); return fa[x];}
map<int,bool> pan;
int main()
{
	while(cin>>n>>m)
	{
		if(n==-1&&m==-1) break;
		pan.clear();
		int flag=0;edge=num=0;
		for(int i=1;i<=N;i++) fa[i]=i;
		if(n==0&&m==0)
		{
			puts("Yes");
			continue;
		}
		if(n!=0&&m!=0)
		{
			edge++;
			if(!pan[n]) pan[n]=true,num++;
			if(!pan[m]) pan[m]=true,num++;
			int a=findx(n),b=findx(m);
			if(a==b) flag=1;
			else fa[a]=b;
		}
		while(cin>>n>>m&&(m!=0&&n!=0)) 
		{
			edge++;
			if(!pan[n]) pan[n]=true,num++;
			if(!pan[m]) pan[m]=true,num++;
			int a=findx(n),b=findx(m);
			if(a==b) flag=1;
			else fa[a]=b;
		}
		if(flag) puts("No");
		else if(num==edge+1) puts("Yes");
		else puts("No");
	}
	return 0;
}
