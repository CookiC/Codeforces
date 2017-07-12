//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cstring>
#include<set>
#define maxn 200
//#pragma warning(disable : 4996)
using namespace std;

int a,b,l,r;
char s[maxn];
bool vis[30];
set<char> st;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	char c;
	int i,j;
	cin>>a>>b>>l>>r;
	memset(vis,0,sizeof(vis));
	for(i=0;i<a;++i){
		s[i]=i+1;
		vis[s[i]]=1;
	}
	do{
		for(j=0;j<b;++j)
			s[i+j]=s[i-1];
		i+=b;
		c=1;
		for(j=0;j<a;++j){
			while(vis[c]) ++c;
			s[i+j]=c;
			vis[c]=1;
		}
		for(j=1;j<=a+b;++j)
			vis[s[i-j]]=0;
	}
	return 0;
}

