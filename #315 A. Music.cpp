//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int T,S,q,ans=1;
	cin>>T>>S>>q;
	while(T>S*q){
		S+=S*(q-1);
		++ans;
	}
	cout<<ans<<endl;
	return 0;
}

