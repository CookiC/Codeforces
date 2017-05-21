//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<map>
#include<string>
//#pragma warning(disable : 4996)
using namespace std;

int n,sum;
string str;
map<string,int> m;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	m["Tetrahedron"]=4;
	m["Cube"]=6;
	m["Octahedron"]=8;
	m["Dodecahedron"]=12; 
	m["Icosahedron"]=20;
	cin>>n;
	sum=0;
	for(int i=0;i<n;++i){
		cin>>str;
		sum+=m[str];
	}
	cout<<sum;
	return 0;
}

