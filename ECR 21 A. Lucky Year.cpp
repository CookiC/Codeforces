//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

int n;

int f(int n){
	int p=1;
	while(p<=n)
		p*=10;
	p/=10;
	return p-n%p;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n;
	if(n<10)
		cout<<1<<endl;
	else
		cout<<f(n)<<endl;
	return 0;
}

