//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<string>
//#pragma warning(disable : 4996)
using namespace std;

string s;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i;
	bool b=1;
	cin>>s;
	for(i=0;b&&i<s.size()-1;++i)
		if(s[i]=='V'&&s[i+1]=='V'&&(i+2>=s.size()||s[i+2]=='V')) {
			b=0;
			s[i+1]='K';
		}
	for(i=1;b&&i<s.size();++i)
		if(s[i]=='K'&&s[i-1]=='K'&&(i-2<0||s[i-2]=='K')) {
			b=0;
			s[i-1]='V';
		}
	
	int ans=0;
	for(i=1;i<s.size();++i)
		if(s[i-1]=='V'&&s[i]=='K')
			++ans;
	
	cout<<ans<<endl;
	return 0;
}

