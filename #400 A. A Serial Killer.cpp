//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<string>
//#pragma warning(disable : 4996)
using namespace std;

int n;
string a,b,c,d;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>a>>b>>n;
	cout<<a<<' '<<b<<endl;
	for(int i=0;i<n;++i){
		cin>>c>>d;
		if(a==c)
			a=d;
		else
			b=d;
		cout<<a<<' '<<b<<endl;
	}
	return 0;
}

