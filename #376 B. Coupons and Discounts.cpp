//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

int n,a,b;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	bool ans=1;
	cin>>n;
	b=0;
	for(int i=0;i<n&&ans;++i){
		cin>>a;
		if(b&&!a){
			ans=0;
			break;
		}
		a-=b;
		if(a%2)
			b=1;
		else
			b=0;
	}
	if(b)
		ans=0;
	if(ans)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}

