//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<string>
//#pragma warning(disable : 4996)
using namespace std;

int n,k;

bool query(int L,int R){
	static string s;
	cout<<1<<' '<<L<<' '<<R<<endl;
	cin>>s;
	if(s=="TAK")
		return true;
	return false;
}

int find(int L,int R){
	int M;
	while(L<R){
		M=(L+R)/2;
		if(query(M,M+1))
			R=M;
		else
			L=M+1; 
	}
	if(L==R)
		return L;
	return -1;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int x,y;
	cin>>n>>k;
	x=find(1,n);
	y=find(1,x-1);
	if(y==-1||!query(y,x))
		y=find(x+1,n);
	cout<<2<<' '<<x<<' '<<y<<endl;
	return 0;
}

