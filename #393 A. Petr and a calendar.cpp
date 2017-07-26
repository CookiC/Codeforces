//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

int m,d;
int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>m>>d;
	int ans=0;
	if(d!=1){
		++ans;
		d=month[m]-(7-d+1);
	}
	else
		d=month[m];
	ans+=(d+6)/7;
	cout<<ans<<endl;
	return 0;
}

