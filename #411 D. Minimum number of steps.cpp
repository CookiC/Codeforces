//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cstdio>
#define LL long long unsigned
#define maxn 1000010
using namespace std;

const LL Mod=1e9+7;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	LL cnt=0;
	LL ans=0;
	char c;
	while(true){
		c=getchar();
		if(c=='a')
			cnt=(cnt*2+1)%Mod;
		else if(c=='b')
			ans=(ans+cnt)%Mod;
		else
			break;
	}
	cout<<ans<<endl;
	return 0;
}

