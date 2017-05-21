//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

int n,i,cnt,t;
int a[6],b[6];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n;
	for(i=0;i<n;++i){
		cin>>t;
		++a[t];
	}
	for(i=0;i<n;++i){
		cin>>t;
		++b[t];
	}
	
	cnt=0;
	for(i=1;i<=5;++i){
		if((a[i]+b[i])%2)
			break;
		if(a[i]>b[i])
			cnt+=(a[i]-b[i])/2;
	}
	
	if(i<=5)
		cout<<-1<<endl;
	else
		cout<<cnt<<endl;
	return 0;
}

