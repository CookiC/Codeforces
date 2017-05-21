//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<set>
#include<cmath>
#define LL long long int
//#pragma warning(disable : 4996)
using namespace std;

bool inf;
LL q,l,m,b1,bi,i,cnt=0,a;
set<LL> vis;
set<LL> s;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>bi>>q>>l>>m;
	for(i=0;i<m;++i){
		cin>>a;
		vis.insert(a);
	}
	while(abs(bi)<=l){
		if(s.find(bi)!=s.end()){
			if(q!=0||vis.find(0)==vis.end())
				inf=true;
			break;
		}
		s.insert(bi);
		bi*=q;
	}
	for(auto it=s.begin();it!=s.end();++it)
		if(abs(*it)<=l&&vis.find(*it)==vis.end())
			++cnt;
	if(cnt&&inf)
		cout<<"inf"<<endl;
	else
		cout<<cnt<<endl;
	return 0;
}

