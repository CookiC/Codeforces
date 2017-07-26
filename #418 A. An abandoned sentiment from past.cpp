//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#define maxn 110
//#pragma warning(disable : 4996)
using namespace std;

int n,k,b;
int a[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i;
	cin>>n>>k;
	if(k==1){
		for(i=0;i<n;++i)
			cin>>a[i];
		cin>>b;
		for(i=0;i<n;++i)
			if(!a[i]){
				a[i]=b;
				break;
			}
		for(i=1;i<n&&a[i]>=a[i-1];++i);
		if(i<n)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	else
		cout<<"Yes"<<endl;
	return 0;
}

