//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
//#pragma warning(disable : 4996)
using namespace std;

double n,a;
int len;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n>>a;
	len=min(max(1,int(a*n/180+0.5)),(int)n-2);
	cout<<1<<' '<<len+2<<' '<<len+1<<endl;
	return 0;
}

