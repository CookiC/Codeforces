//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

char field[4][4];

bool win(){
	for(int i=0;i<4;++i)
		for(int j=0;j<4;++j)
			if(field[i][j]=='x'&&(0<i&&i<3&&field[i-1][j]=='x'&&field[i+1][j]=='x'||
				0<j&&j<3&&field[i][j-1]=='x'&&field[i][j+1]=='x'||0<i&&i<3&&0<j&&j<3&&(
				field[i-1][j-1]=='x'&&field[i+1][j+1]=='x'||
				field[i-1][j+1]=='x'&&field[i+1][j-1]=='x')))
				return true;
	return false;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j;
	for(i=0;i<4;++i)
		cin>>field[i];
	
	bool ans=0;
	for(i=0;i<4&&!ans;++i)
		for(j=0;j<4&!ans;++j)
			if(field[i][j]=='.'){
				field[i][j]='x';
				if(win()){
					ans=1;
					break;
				}
				field[i][j]='.';
			}
	if(ans)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}

