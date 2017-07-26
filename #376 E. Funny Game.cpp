//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define LL long long
#define maxn 200010 
//#pragma warning(disable : 4996)
using namespace std;

int sum[maxn],a[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>a[i];
		sum[i]+=a[i];
	}
	
	return 0;
}

