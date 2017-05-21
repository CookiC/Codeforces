//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<string>
#define maxn 60
//#pragma warning(disable : 4996)
using namespace std;

string toStr(int n){
	string str="";
	str+=char('A'+n%26);
	n/=26;
	while(n){
		str+=char('a'+n%26);
		n/=26;
	}
	return str;
}

int n,k,cnt,i;
int a[maxn];
bool b[maxn];
string str;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n>>k;
	for(i=0;i<n-k+1;++i){
		cin>>str;
		if(str=="NO")
			b[i]=0;
		else
			b[i]=1;
	}
	
	for(i=0,cnt=0;i<k-1;++i)
		a[i]=cnt++;
	
	while(i<n){
		a[i]=b[i-k+1]?cnt++:a[i-k+1];
		++i;
	}
	
	for(i=0;i<n;++i)
		cout<<toStr(a[i])<<' ';
	cout<<endl;
	return 0;
}

