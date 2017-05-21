//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

int n;
char a[3]={0};

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n;
	for(int i=0;i<n;++i){
		if(a[(i+1)%3]!='a')
			a[i%3]='a';
		else
			a[i%3]='b';
		cout<<a[i%3];
	}
	cout<<endl;
	return 0;
}

