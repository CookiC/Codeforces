//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

char s[11][11];

bool ok(){
	for(int i=0;i<10;++i)
		for(int j=0;j<10;++j){
			if(2<=i&&i<8&&s[i-2][j]=='X'&&s[i-1][j]=='X'&&s[i][j]=='X'&&s[i+1][j]=='X'&&s[i+2][j]=='X')
				return true;
			if(2<=j&&j<8&&s[i][j-2]=='X'&&s[i][j-1]=='X'&&s[i][j]=='X'&&s[i][j+1]=='X'&&s[i][j+2]=='X')
				return true;
			if(2<=i&&i<8&&2<=j&&j<8){
				if(s[i-2][j-2]=='X'&&s[i-1][j-1]=='X'&&s[i][j]=='X'&&s[i+1][j+1]=='X'&&s[i+2][j+2]=='X')
					return true;
				if(s[i+2][j-2]=='X'&&s[i+1][j-1]=='X'&&s[i][j]=='X'&&s[i-1][j+1]=='X'&&s[i-2][j+2]=='X')
					return true; 
			}
		}
	return false;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j;
	for(i=0;i<10;++i)
		cin>>s[i];
	bool ans=0;
	for(i=0;i<10&&!ans;++i)
		for(j=0;j<10&&!ans;++j)
			if(s[i][j]=='.'){
				s[i][j]='X';
				if(ok())
					ans=1;
				s[i][j]='.';
			}
	if(ans)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}

