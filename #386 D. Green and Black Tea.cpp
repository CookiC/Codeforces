//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
//#pragma warning(disable : 4996)
using namespace std;

char c[]="GB";
int i,n,k,a,b,x;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n>>k>>a>>b;
	if(a<b){
		swap(a,b);
		swap(c[0],c[1]);
	}
	x=a/k;
	if(a%k)
		++x;
	if(x>b+1){
		putchar('N');
		putchar('O');
	} 
	else{
		while(a-b>=k-1&&b){
			for(i=0;i<k;++i)
				putchar(c[0]);
			a-=k;
			putchar(c[1]);
			--b;
		}
		while(a&&b){
			--a;
			putchar(c[0]);
			--b;
			putchar(c[1]);
		}
		while(a--)
			putchar(c[0]);
	}
	putchar('\n');
	return 0;
}

