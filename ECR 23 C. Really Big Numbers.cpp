//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define LL long long
//#pragma warning(disable : 4996)
using namespace std;

LL n,s;

bool ok(LL x){
	LL sum=0,y=x;
	while(y){
		sum+=y%10;
		y/=10;
	}
	if(x-sum>=s)
		return true;
	return false;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n>>s;
	LL L=1,R=n+1,M;
	while(L<R){
		M=(L+R)/2;
		if(ok(M))
			R=M;
		else
			L=M+1;
	} 
	cout<<n-L+1<<endl;
	return 0;
}

