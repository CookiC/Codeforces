//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<set>
#define maxn 200010
//#pragma warning(disable : 4996)
using namespace std;

int n,m,even,odd,i,xo=-1,xe=0,cnt=0;
int a[maxn];
set<int> s;

int getO(){
	++cnt;
	do{
		xo+=2;
	}while(s.find(xo)!=s.end());
	return xo;
}

int getE(){
	++cnt;
	do{
		xe+=2;
	}while(s.find(xe)!=s.end());
	return xe;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	s.clear();
	even=odd=0;
	
	cin>>n>>m;
	for(i=0;i<n;++i){
		cin>>a[i];
		if(s.find(a[i])==s.end()){
			s.insert(a[i]);
			if(a[i]%2)
				++odd;
			else
				++even;
		}
		else 
			a[i]=0;
	}
	
	for(i=0;i<n;++i)
		if(!a[i]){
			if(even>odd){
				a[i]=getO();
				++odd;
			}
			else{
				a[i]=getE();
				++even;
			}
		}
	
	for(i=0;even>odd;++i)
		if(!(a[i]%2)){
			a[i]=getO();
			--even;
			++odd;
		}
	
	while(even<odd){
		if(a[i]%2){
			a[i]=getE();
			--odd;
			++even;
		}
		++i;
	}
	
	if(xe>m||xo>m)
		cout<<-1<<endl;
	else{
		cout<<cnt<<endl;
		for(i=0;i<n;++i)
			cout<<a[i]<<' ';
		cout<<endl;
	}
	return 0;
}

