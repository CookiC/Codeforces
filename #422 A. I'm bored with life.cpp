//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
//#pragma warning(disable : 4996)
using namespace std;

int a,b;

int fact(int x){
	int ans=1;
	while(x){
		ans*=x;
		--x;
	}
	return ans;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>a>>b;
	cout<<fact(min(a,b))<<endl;
	return 0;
}

