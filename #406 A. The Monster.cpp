//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

void gcd(int a,int b,int &d,int &x,int &y){
	if(!b){
		d=a;
		x=1;
		y=0;
	}
	else{
		gcd(b,a%b,d,y,x);
		y-=x*(a/b);
	}
}

int x,y,a,b,d,c,k,n,m;
int a0,b0,c0,d0;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>a0>>b0>>c0>>d0;
	a=a0;
	b=-c0;
	c=d0-b0;
	gcd(a,b,d,x,y);
	if(c%d==0){
		b=abs(b/d);
		x*=c/d;
		x%=b;
		while(x<0||b0+x*a0<d0)
			x+=b;
		cout<<b0+x*a0<<endl;
	}
	else
		cout<<-1<<endl;
	return 0;
}

