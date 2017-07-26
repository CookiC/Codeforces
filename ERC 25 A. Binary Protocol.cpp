//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 100
//#pragma warning(disable : 4996)
using namespace std;

int n;
char s[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,cnt;
	cin>>n;
	cin>>s;
	s[n]='0';
	i=0;
	while(i<=n){
		cnt=0;
		while(s[i]=='1'){
			++cnt;
			++i;
		}
		++i;
		cout<<cnt;
	}
	cout<<endl;
	return 0;
}

