//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

int k,a,b,da,db,ma,mb;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>k>>a>>b;
	da=a/k;
	db=b/k;
	ma=a%k;
	mb=b%k;
	if(ma&&!db||mb&&!da)
		cout<<-1<<endl;
	else
		cout<<da+db<<endl;
	return 0;
}

