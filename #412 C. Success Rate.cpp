//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define LL long long
//#pragma warning(disable : 4996)
using namespace std;

int t;
LL x,y,p,q;

LL gcd(LL a,LL b){
	LL t;
	while(b){
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	LL a,b,k;
	cin>>t;
	while(t--){
		cin>>x>>y>>p>>q;
		a=gcd(p,q);
		p/=a;
		q/=a;
		if(p==q||p==0){
			if(p==q&&x==y||p==0&&x==0)
				cout<<0<<endl;
			else
				cout<<-1<<endl;
		}
		else{
			k=max(max((x-1)/p+1,(y-1)/q+1),(y-x-1)/(q-p)+1);
			cout<<k*q-y<<endl;
		}
	}
	return 0;
}

