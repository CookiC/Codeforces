//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxc 256
#define maxn 1010
//#pragma warning(disable : 4996)
using namespace std;

char a[27],b[27],f[maxc];
char s[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int t,i;
	cin>>a>>b;
	for(i=0;i<maxc;++i)
		f[i]=i;
	t='a'-'A';
	for(i=0;i<26;++i){
		f[a[i]]=b[i];
		f[a[i]-t]=b[i]-t;
	}
	cin>>s;
	for(i=0;s[i];++i)
		cout<<f[s[i]];
	cout<<endl;
	return 0;
}

