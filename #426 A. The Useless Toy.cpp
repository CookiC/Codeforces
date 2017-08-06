//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

int n;
char a,b;

int ci(char c){
	switch(c){
		case 118:return 0;
		case 60:return 1;
		case 94:return 2;
		case 62:return 3;
	}
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>a>>b;
	cin>>n;
	if(n%4==2||n%4==0)
		cout<<"undefined"<<endl;
	else if((ci(a)+n)%4==ci(b))
		cout<<"cw"<<endl;
	else
		cout<<"ccw"<<endl;
	return 0;
}

