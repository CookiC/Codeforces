//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

int x[3],y[3];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	for(int i=0;i<3;++i)
		cin>>x[i]>>y[i];
	cout<<3<<endl;
	cout<<x[0]+x[1]-x[2]<<' '<<y[0]+y[1]-y[2]<<endl;
	cout<<x[0]-x[1]+x[2]<<' '<<y[0]-y[1]+y[2]<<endl;
	cout<<-x[0]+x[1]+x[2]<<' '<<-y[0]+y[1]+y[2]<<endl;
	return 0;
}

