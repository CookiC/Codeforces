//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

int n;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n;
	cout<<n/2<<endl;
	for(int i=0;i<n/2-1;++i)
		cout<<2<<' ';
	if(n%2)
		cout<<3<<endl;
	else
		cout<<2<<endl;
	return 0;
}

