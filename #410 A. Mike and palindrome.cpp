//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cstring>
//#pragma warning(disable : 4996)
using namespace std;

int i,len;
char s[20];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int cnt=0;
	cin>>s;
	len=strlen(s);
	for(i=0;i<=len/2-1;++i)
		if(s[i]!=s[len-1-i])
			++cnt;
	if(cnt==1||len%2&&cnt==0)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}

