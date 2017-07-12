//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

int c,v0,v1,a,l,i,v;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>c>>v0>>v1>>a>>l;
	v=v0;
	i=v0;
	int day=1;
	while(i<c){
		v=min(v+a,v1);
		i=i-l+v;
		++day;
	}
	cout<<day<<endl;
	return 0;
}

