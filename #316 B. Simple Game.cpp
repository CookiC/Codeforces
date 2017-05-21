//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int n,m;
	cin>>n>>m;
	if(n==1)
		cout<<1<<endl;
	else if(n-m>m-1)
		cout<<m+1<<endl;
	else
		cout<<m-1<<endl;
	return 0;
}

