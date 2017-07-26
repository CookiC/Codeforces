//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 110
//#pragma warning(disable : 4996)
using namespace std;

int n;
int a[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i;
	cin>>n;
	for(i=0;i<n;++i)
		cin>>a[i];
	i=0;
	while(i<n-1&&a[i]<a[i+1])
		++i;
	while(i<n-1&&a[i]==a[i+1])
		++i;
	while(i<n-1&&a[i]>a[i+1])
		++i;
	if(i==n-1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}

