//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

int n,k,cnt,i;
int w;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cnt=0;
	cin>>n>>k;
	for(i=0;i<n;++i){
		cin>>w;
		cnt+=w%k?w/k+1:w/k;
	}
	cout<<(cnt%2?cnt/2+1:cnt/2)<<endl;
	return 0;
}

