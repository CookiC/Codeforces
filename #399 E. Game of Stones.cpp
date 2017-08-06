//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxa 70
//#pragma warning(disable : 4996)
using namespace std;

int n,a;
int S[maxa];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,x,y,ans=0;
	x=1;
	y=1;
	for(i=0;i<maxa;++i){
		if(i>=x)
			x+=++y;
		S[i]=y-1;
	} 
	cin>>n;
	for(i=0;i<n;++i){
		cin>>a;
		ans^=S[a];
	}
	if(ans)
		puts("NO");
	else
		puts("YES");
	return 0;
}

