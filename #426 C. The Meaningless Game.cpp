//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cstdio>
#define LL long long
//#pragma warning(disable : 4996)
using namespace std;

LL a,b;

bool QIn(LL &x){
	char c;
	while((c=getchar())!=EOF&&!isdigit(c));
	if(c==EOF)
		return false;
	x=0;
	do{
		x*=10;
		x+=c-'0';
	}while((c=getchar())!=EOF&&isdigit(c));
	return true;
}

bool QIn(int &x){
	char c;
	while((c=getchar())!=EOF&&!isdigit(c));
	if(c==EOF)
		return false;
	x=0;
	do{
		x*=10;
		x+=c-'0';
	}while((c=getchar())!=EOF&&isdigit(c));
	return true;
}

void QOut(const char *p){
	while(*p)
		putchar(*p++);
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
//	ios::sync_with_stdio(false);
	
	int n;
	QIn(n);
	while(n--){
		QIn(a);
		QIn(b);
		LL L=0,R=1e6+1,M;
		while(L<R){
			M=L+(R-L)/2;
			if(M*M*M<a*b)
				L=M+1;
			else
				R=M;
		}
		if(L*L*L==a*b&&a%L==0&&b%L==0)
			QOut("Yes\n");
		else
			QOut("No\n");
	}
	return 0;
}
