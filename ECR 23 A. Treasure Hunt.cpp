//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

int gcd(int a,int b){
	int t;
	while(b){
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int x1,y1,x2,y2,x,y,a,b;
	cin>>x1>>y1>>x2>>y2>>x>>y;
	a=abs(x2-x1);
	b=abs(y2-y1);
	if(a%x==0&&b%y==0&&(a/x-b/y)%2==0)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}

