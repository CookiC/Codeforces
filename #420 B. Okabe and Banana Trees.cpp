//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxb 10010
#define LL long long
//#pragma warning(disable : 4996)
using namespace std;

int m,b,t;

LL banana(LL x,LL y){
	return (y*(y+1)+x*(y+1))*(x+1)/2;
} 

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	LL i,j;
	cin>>m>>b;
	LL ans=0;
	for(i=0;i<=b*m;++i)
		if(i%m==0&&banana(i,b-i/m)>ans)
			ans=banana(i,b-i/m);
	cout<<ans<<endl;
	return 0;
}

