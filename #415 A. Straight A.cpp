//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

int n,k,i,x;
double sum;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n>>k;
	sum=0;
	for(i=0;i<n;++i){
		cin>>x;
		sum+=x;
	}
	int ans=0;
	while(sum/n+0.5<k){
		sum+=k;
		++n;
		++ans;
	}
	cout<<ans<<endl;
	return 0;
}

