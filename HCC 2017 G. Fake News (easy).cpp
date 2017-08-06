//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cstring>
#define maxn 1010
//#pragma warning(disable : 4996)
using namespace std;

char s[maxn],t[]="heidi";

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j;
	cin>>s;
	for(i=0,j=0;s[i]&&t[j];++i)
		if(s[i]==t[j])
			++j;
	if(j==5)
		puts("YES");
	else
		puts("NO");
	return 0;
}

