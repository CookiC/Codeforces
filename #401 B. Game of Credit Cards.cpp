//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
//#pragma warning(disable : 4996)
using namespace std;

char a[1010],b[1010];
int i,j,n,cnt;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n>>a>>b;
	sort(a,a+n);
	sort(b,b+n);
	i=n-1;
	j=n-1;
	cnt=0;
	do{
		while(i>=0&&a[i]>b[j]){
			++cnt;
			--i;
		}
		if(i<0)	break;
		--i;--j;
	}while(j>=0);
	cout<<cnt<<endl;
	i=n-1;
	j=n-1;
	cnt=0;
	do{
		while(i>=0&&a[i]>=b[j]) --i;
		if(i<0) break;
		++cnt;
		--i;--j;
	}while(j>=0);
	cout<<cnt<<endl;
	return 0;
}

