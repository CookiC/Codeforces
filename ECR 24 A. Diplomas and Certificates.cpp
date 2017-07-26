//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define LL long long
//#pragma warning(disable : 4996)
using namespace std;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	LL n,k;
	cin>>n>>k;
	LL x=n/2/(k+1);
	LL y=x*k;
	LL z=n-x-y;
	cout<<x<<' '<<y<<' '<<z<<endl; 
	return 0;
}

