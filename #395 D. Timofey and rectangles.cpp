//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 500010
//#pragma warning(disable : 4996)
using namespace std;

int n;
int C[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int a,b,c,d,i;
	cin>>n;
	for(i=0;i<n;++i){
		cin>>a>>b>>c>>d;
		a=min(a,c);
		b=min(b,d);
		if(a&1){
			if(b&1)
				C[i]=1;
			else
				C[i]=2;
		}
		else{
			if(b&1)
				C[i]=3;
			else
				C[i]=4;
		}
	}
	
	cout<<"YES"<<endl;
	for(i=0;i<n;++i)
		cout<<C[i]<<endl;
	return 0;
}

