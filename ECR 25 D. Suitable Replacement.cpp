//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 1000010
//#pragma warning(disable : 4996)
using namespace std;

char s[maxn],t[maxn];
int sc[300],tc[300];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j;
	cin>>s>>t;
	for(i=0;s[i];++i)
		++sc[s[i]];
	for(i=0;t[i];++i)
		++tc[t[i]];
	int sum=0;
	while(sum+sc['?']>=0){
		for(i='a';i<='z';++i)
			sc[i]-=tc[i];
		sum=0;
		for(i='a';i<='z';++i)
			if(sc[i]<0)
				sum+=sc[i];
	}
/*	for(i='a';i<='z';++i)
		cout<<(char)i<<' ';
	cout<<endl;*/
	for(i='a';i<='z';++i){
		sc[i]+=tc[i];
//		cout<<sc[i]<<' ';
	}
//	cout<<endl;
	j='a';
	for(i=0;s[i];++i)
		if(s[i]=='?'){
			while(j<='z'&&sc[j]>=0)
				++j;
			if(j<='z'){
				s[i]=j;
				++sc[j];
			}
			else
				s[i]='a';
		}
	cout<<s<<endl;
	return 0;
}

