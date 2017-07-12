//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

bool ok(int p,int s){
	int i=25;
	int j=s/50%475;
	while(i--){
    	j=(j*96+42)%475;
    	if(j+26==p)
    		return true;
    }
    return false;
}

int p,x,y;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>p>>x>>y;
	int i=x;
	while(i>=y){
		if(ok(p,i)){
			cout<<'0'<<endl;
			break;
		}
		i-=50;
	}
	if(i<y){
		i=x;
		do{
			i+=50;
		}while(!ok(p,i));
		cout<<(i-x+50)/100<<endl;
	}
	return 0;
}

