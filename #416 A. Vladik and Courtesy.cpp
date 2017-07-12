//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cmath>
//#pragma warning(disable : 4996)
using namespace std;

int a,b;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i=1;
	cin>>a>>b;
	while(true){
		a-=i++;
		if(a<0){
			cout<<"Vladik"<<endl;
			break;
		}
		b-=i++;
		if(b<0){
			cout<<"Valera"<<endl;
			break;
		}
	}
	return 0;
}

