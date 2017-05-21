//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<map>
#include<string>
#include<bitset>
#include<sstream>
#define maxn 5010
#define maxm 1010
//#pragma warning(disable : 4996)
using namespace std;

int n,m;
map<string,bitset<maxm> > mp;

struct Expre{
	bool e;
	char o;
	string n,a,b;
	
	void cal(){
		if(e)
			switch(o){
				case 'O':mp[n]=mp[a]|mp[b];return;
				case 'A':mp[n]=mp[a]&mp[b];return;
				case 'X':mp[n]=mp[a]^mp[b];return;
			}
	}
}E[maxn];

int C0[maxm],C1[maxm];

void Count(int *C){
	int i;
	for(auto it=mp.begin();it!=mp.end();++it)
		if(it->first!="?"){
			bitset<maxm> &x=it->second;
			for(i=0;i<m;++i)
				if(x[i])
					++C[i];
		}
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j;
	string s,a,b,o;
	istringstream iss;
	bitset<maxm> x;
	
	cin>>n>>m;
	getline(cin,s);
	
	for(i=0;i<n;++i){
		getline(cin,s);
		iss.clear();
		iss.str(s);
		iss>>s>>o;
		iss>>a;
		E[i].n=s;
		if(iss>>o>>b){
			E[i].e=1;
			E[i].a=a;
			E[i].o=o[0];
			E[i].b=b;
		}
		else{
			E[i].e=0;
			for(j=0;j<m;++j)
				x[j]=a[j]-'0';
			mp[E[i].n]=x;
		}
	}
	
	x.reset();
	mp["?"]=x;
	for(i=0;i<n;++i){
		E[i].cal();
		bitset<maxm> &y=mp[E[i].n];
	}
	Count(C0);

	x.set();
	mp["?"]=x;
	for(i=0;i<n;++i){
		E[i].cal();
		bitset<maxm> &y=mp[E[i].n];
	}
	Count(C1);

	for(i=0;i<m;++i)
		if(C0[i]<=C1[i])
			cout<<0;
		else
			cout<<1;
	cout<<endl;
	
	for(i=0;i<m;++i)
		if(C0[i]>=C1[i])
			cout<<0;
		else
			cout<<1;
	cout<<endl;
	return 0;
}

