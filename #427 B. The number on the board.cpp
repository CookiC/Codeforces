//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#define maxn 100010
//#pragma warning(disable : 4996)
using namespace std;

int k,n,s[maxn],sum=0;
char c;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i;
	cin>>k;
	for(i=0;cin>>c;++i){
		s[i]=c-'0';
		sum+=s[i];
	}
	n=i;
	if(sum<k){
		sort(s,s+n);
		for(i=0;i<n&&sum<k;++i)
			sum+=9-s[i];
		cout<<i<<endl;
	}
	else
		cout<<0<<endl;
	return 0;
}

