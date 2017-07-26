//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cstring>
#define maxn 100010
//#pragma warning(disable : 4996)
using namespace std;

int la,lb;
char a[maxn],b[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>a>>b;
	la=strlen(a);
	lb=strlen(b);
	if(strcmp(a,b)!=0)
		cout<<max(la,lb)<<endl;
	else
		cout<<-1<<endl;
	return 0;
}

