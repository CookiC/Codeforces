//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

string x,y,z;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i;
	cin>>x>>y;
	for(i=0;i<x.size();++i)
		if(x[i]<y[i])
			break;
	if(i==x.size())
		cout<<y<<endl;
	else
		cout<<-1<<endl;
	return 0;
}

