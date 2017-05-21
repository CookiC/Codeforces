//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

int l,r;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>l>>r;
	if(l==r)
		cout<<l<<endl;
	else
		cout<<2<<endl;
	return 0;
}

