//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

int n,a,b,d;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int c,ans=0,i;
	cin>>n>>a>>b;
	d=0;
	for(i=0;i<n;++i){
		cin>>c;
		if(c==1){
			if(a)
				--a;
			else if(b){
				--b;
				++d;
			}
			else if(d)
				--d;
			else
				++ans;
		}
		else if(b)
			--b;
		else
			ans+=2;
	}
	cout<<ans<<endl;
	return 0;
}

