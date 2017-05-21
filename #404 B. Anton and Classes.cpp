//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
#define INF 0x7FFFFFFF
using namespace std;

int n,m,i;
int l,r,l1=0,r1=INF,l2=0,r2=INF;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n;
	for(i=0;i<n;++i){
		cin>>l>>r;
		if(l>l1)
			l1=l;
		if(r<r1)
			r1=r;
	}
	cin>>m;
	for(i=0;i<m;++i){
		cin>>l>>r;
		if(l>l2)
			l2=l;
		if(r<r2)
			r2=r;
	}
	cout<<max(0,max(l2-r1,l1-r2))<<endl;
	return 0;
}

