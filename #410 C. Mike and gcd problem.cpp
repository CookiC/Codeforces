//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 100007
//#pragma warning(disable : 4996)
using namespace std;

int Gcd(int a,int b){
	int t;
	while(b){
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}

int a[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,t,n;
	cin>>n;
	for(i=0;i<n;++i)
		cin>>a[i];
	
	t=a[0];
	for(i=1;i<n;++i)
		t=Gcd(t,a[i]);
	
	cout<<"YES"<<endl;
	if(t>1)
		cout<<0<<endl;
	else{
		int cnt=0;
		for(i=0;i<n-1;++i)
			if(a[i]%2)
				if(a[i+1]%2){
					++cnt;
					a[i+1]=2;
				}
				else
					cnt+=2;
		if(a[i]%2)
			cnt+=2;
		cout<<cnt<<endl;
	}
	return 0;
}

