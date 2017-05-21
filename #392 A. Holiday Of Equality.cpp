//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 110
//#pragma warning(disable : 4996)
using namespace std;

int a[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int n,maxa=0,i;
	cin>>n;
	for(i=0;i<n;++i){
		cin>>a[i];
		if(maxa<a[i])
			maxa=a[i];
	}
	
	int sum=0;
	for(i=0;i<n;++i)
		sum+=maxa-a[i];
	
	cout<<sum<<endl;
	return 0;
}

