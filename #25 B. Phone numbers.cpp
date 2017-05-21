//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

int n;
string s;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n>>s;
	for(int i=0;i<n;++i){
		cout<<s[i];
		if((i&1)&&i<n-2)
			cout<<'-';
	}
	return 0;
}

