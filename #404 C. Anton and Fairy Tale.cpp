//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cmath>
#define LL long long int
//#pragma warning(disable : 4996)
using namespace std;

int N;
LL n,m,x;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n>>m;
	if(n<=m)
		cout<<n<<endl;
	else{
		//(1+x)*x>=n-m
		x=sqrt((n-m)*2);
		if(x*(x+1)<(n-m)*2)
			++x;
		cout<<m+x<<endl;
	}
	return 0;
}

