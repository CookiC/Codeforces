//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

int a,b,i;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>a>>b;
	for(i=0;a<=b;++i){
		a*=3;
		b*=2;
	}
	cout<<i<<endl;
	return 0;
}

