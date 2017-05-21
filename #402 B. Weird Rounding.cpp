//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<string>
//#pragma warning(disable : 4996)
using namespace std;

int k,cnt,i,j;
string n;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n>>k;
	if(k>n.size())
		cout<<n.size()-1<<endl;
	else{
		for(cnt=0,i=n.size()-1,j=k;i>0&&j;--i)
			if(n[i]=='0')
				--j;
			else
				++cnt;

		if(j)
			cout<<n.size()-1<<endl;
		else
			cout<<cnt<<endl;
	}
	return 0;
}

