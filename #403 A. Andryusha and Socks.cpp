//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<set>
//#pragma warning(disable : 4996)
using namespace std;

int n;
set<int> a;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,t,ans;
	cin>>n;
	ans=0;
	for(i=0;i<2*n;++i){
		cin>>t;
		if(a.find(t)==a.end())
			a.insert(t);
		else
			a.erase(t);
		if(ans<a.size())
			ans=a.size();
	}
	cout<<ans<<endl;
	return 0;
}

