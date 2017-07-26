//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define LL long long
//#pragma warning(disable : 4996)
using namespace std;

LL n,k;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n>>k;
	LL x=n%(2*k);
	if(x<k)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
	return 0;
}

