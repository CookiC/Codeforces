//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

int n,k;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int t,i,j,u,v,a,b;
	cin>>n>>k;
	a=n%k;
	b=n/k;
	u=1;
	v=2;
	if(a==0){
		if(k>2)
			cout<<b*2<<endl;
		else
			cout<<b*2-1<<endl;
		for(i=0;i<b-1;++i){
			cout<<u<<' '<<v<<endl;
			u=v++;
		}
		for(i=0;i<k-1;++i){
			u=1;
			for(j=0;j<b;++j){
				cout<<u<<' '<<v<<endl;
				u=v++;
			}
		}
	}
	else if(a==1){
		cout<<b*2<<endl;
		for(i=0;i<k;++i){
			u=1;
			for(j=0;j<b;++j){
				cout<<u<<' '<<v<<endl;
				u=v++;
			}
		}
	}
	else if(a==2){
		cout<<b*2+1<<endl;
		u=1;
		for(i=0;i<b+1;++i){
			cout<<u<<' '<<v<<endl;
			u=v++;
		}
		for(i=0;i<k-1;++i){
			u=1;
			for(j=0;j<b;++j){
				cout<<u<<' '<<v<<endl;
				u=v++;
			}
		}
	}
	else{
		cout<<(b+1)*2<<endl;
		for(v=2;v<a+1;++v)
			cout<<u<<' '<<v<<endl;
		int x=0;
		for(i=0;i<k;++i){
			u=x+2;
			x=(x+1)%(a-1);
			for(j=0;j<b;++j){
				cout<<u<<' '<<v<<endl;
				u=v++;
			}
		}
	}
	return 0;
}

