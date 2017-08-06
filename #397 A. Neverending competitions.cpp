//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<string>
#include<set>
//#pragma warning(disable : 4996)
using namespace std;

int n;
string home,a,b;
set<string> s;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i;
	cin>>n>>home;
	for(i=0;i<n;++i){
		cin>>a;
		if(a.substr(0,3)==home)
			b=a.substr(5,3);
		else
			b=a.substr(0,3);
		if(s.find(b)==s.end())
			s.insert(b);
		else
			s.erase(b);
	}
	if(s.empty())
		cout<<"home"<<endl;
	else
		cout<<"contest"<<endl;
	return 0;
}

