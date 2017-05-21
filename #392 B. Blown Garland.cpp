//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

string s;
int cnt[4],pos[4];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i;
	cin>>s;
	for(i=0;i<s.size();++i)
		switch(s[i]){
			case 'R':pos[i%4]=0;break;
			case 'B':pos[i%4]=1;break;
			case 'Y':pos[i%4]=2;break;
			case 'G':pos[i%4]=3;break;
		}
	
	for(i=0;i<s.size();++i)
		if(s[i]=='!')
			++cnt[pos[i%4]];
	
	for(i=0;i<4;++i)
		cout<<cnt[i]<<' ';
	cout<<endl;
	return 0;
}

