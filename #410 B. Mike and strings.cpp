//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 60
#define INF 0x7FFFFFFF
//#pragma warning(disable : 4996)
using namespace std;

int n,m;
string s[maxn];
 
int match(string &a,string &b){
	int i,j;
	for(i=0;i<m;++i){
		for(j=0;a[j]==b[(i+j)%m]&&j<m;++j);
		if(j>=m)
			return i;
	}
	return -1;
}
 
int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j,k;
	cin>>n;
	for(i=0;i<n;++i)
		cin>>s[i];
	m=s[0].size();
	
	
	bool b=true;
	int minc=INF;
	int c;
	for(i=0;i<n&&b;++i){
		c=0;
		for(j=0;j<n;++j)
			if(i!=j){
				k=match(s[i],s[j]);
				if(k<0){
					b=0;
					break;
				}
				c+=k;
			}
		
		if(minc>c)
			minc=c;
	}
	
	if(b)
		cout<<minc<<endl;
	else
		cout<<-1<<endl;
	return 0;
}

