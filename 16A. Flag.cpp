//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 110
//#pragma warning(disable : 4996)
using namespace std;

int n,m;
char s[maxn][maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j;
	bool flag;
	cin>>n>>m;
	for(i=0;i<n;++i)
		cin>>s[i];
	
	flag=true;
	for(i=0;i<n;++i)
		for(j=0;j<m;++j){
			if(s[i][0]!=s[i][j])
				flag=false;
			if(i&&s[i-1][j]==s[i][j])
				flag=false;
		}

	if(flag)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl; 
	return 0;
}

