//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
//#pragma warning(disable : 4996)
using namespace std;

int a,b,c;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>a>>b>>c;
	cout<<min(a,min(b/2,c/4))*7<<endl;
	return 0;
}

