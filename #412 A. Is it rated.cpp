//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 1010
//#pragma warning(disable : 4996)
using namespace std;

int n;
int a[maxn],b[maxn];

int rated(){
	int i;
	for(i=0;i<n;++i)
		if(a[i]!=b[i])
			return 1;
	for(i=0;i<n-1;++i)
		if(a[i]<a[i+1])
			return -1;
	return 0;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i;
	cin>>n;
	for(i=0;i<n;++i)
		cin>>a[i]>>b[i];
	int r=rated();
	if(r==1)
		cout<<"rated"<<endl;
	else if(r==0)
		cout<<"maybe"<<endl;
	else
		cout<<"unrated"<<endl;
	return 0;
}

