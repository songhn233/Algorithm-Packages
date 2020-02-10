#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
double h,l;
int main()
{
    cin>>h>>l;
    printf("%.13lf",(l*l-h*h)/(2*h));
    return 0;
}
