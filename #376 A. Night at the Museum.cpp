//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cmath>
#include<algorithm>
#define maxn 110
//#pragma warning(disable : 4996)
using namespace std;

int ans=0;
char s[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int t;
	cin>>(s+1);
	s[0]='a';
	for(int i=1;s[i];++i){
		t=abs(s[i]-s[i-1]);
		ans+=min(t,26-t);
	}
	cout<<ans<<endl;
	return 0;
}

