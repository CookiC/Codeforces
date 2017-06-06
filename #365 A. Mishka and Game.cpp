//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

int n,m,c,mcnt=0,ccnt=0;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>m>>c;
		if(m>c)
			++mcnt;
		else if(m<c)
			++ccnt;
	}
	if(mcnt==ccnt)
		cout<<"Friendship is magic!^^"<<endl;
	else if(mcnt>ccnt)
		cout<<"Mishka"<<endl;
	else
		cout<<"Chris"<<endl;
	return 0;
}

