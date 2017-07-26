//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define INF 0x7FFFFFFF
//#pragma warning(disable : 4996)
using namespace std;

int a,n,l,r,m;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int sum=0,i;
	cin>>n;
	for(i=0;i<n;++i){
		cin>>a;
		sum+=a;
	}
	int minl=INF;
	cin>>m;
	for(i=0;i<m;++i){
		cin>>l>>r;
		if(r>=sum){
			if(l>=sum)
				minl=min(minl,l);
			else
				minl=sum;
		}
	}
	if(minl==INF)
		cout<<-1<<endl;
	else
		cout<<minl<<endl;
	return 0;
}

