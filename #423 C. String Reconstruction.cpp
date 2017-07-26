//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<string>
#define maxn 100010
#define maxl 2000010
//#pragma warning(disable : 4996)
using namespace std;

int n;
int pos[maxl];
string s[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j,k,t,len=0;
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>s[i]>>k;
		for(j=0;j<k;++j){
			cin>>t;
			if(s[i].size()>s[pos[t]].size())
				pos[t]=i;
			if(s[i].size()+t-1>len)
				len=s[i].size()+t-1;
		}
	}
	
	j=0;
	k=pos[1];
	for(i=1;i<=len;++i){
		if(s[k].size()-j<s[pos[i]].size()){
			k=pos[i];
			j=0;
		}
		if(j<s[k].size())
			cout<<s[k][j++];
		else
			cout<<'a';
	}
	cout<<endl;
	return 0;
}

