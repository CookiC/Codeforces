//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 510
//#pragma warning(disable : 4996)
using namespace std;

char a,c;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	bool ans=1;
	a='a'-1;
	while(cin>>c){
		if(c>a)
			if(c==a+1)
				a=c;
			else{
				ans=0;
				break;
			}
	}
	if(ans)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}

