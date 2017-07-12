//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

char s[6];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>s;
	int a=(s[0]-'0')*10+s[1]-'0';
	int b=(s[3]-'0')*10+s[4]-'0';
	int ans=0;
	while(!(a/10==b%10&&a%10==b/10)){
		++b;
		a+=b/60;
		b%=60;
		a%=24;
		++ans;
	}
	cout<<ans<<endl;
	return 0;
}

