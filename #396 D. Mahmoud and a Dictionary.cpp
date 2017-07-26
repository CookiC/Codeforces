//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<map>
#define maxn 100010
//#pragma warning(disable : 4996)
using namespace std;

int P[maxn*2];
map<string,int> dic;

int find(int x){
	if(x==P[x])
		return x;
	return P[x]=find(P[x]);
}

int n,m,q;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,x,y;
	string s,t;
	cin>>n>>m>>q;
	for(i=0;i<n;++i){
		cin>>s;
		dic[s]=i*2;
		P[i*2]=i*2;
		P[i*2+1]=i*2+1;
	}
	int r;
	for(i=0;i<m;++i){
		cin>>r>>s>>t;
		x=find(dic[s]);
		y=find(dic[t]);
		if(x==y||(x^1)==y){
			if(r==1&&x==y||r==2&&x==(y^1))
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
		else{
			if(r==1){
				P[y]=x;
				P[y^1]=x^1;
			}
			else{
				P[y^1]=x;
				P[y]=x^1;
			}
			cout<<"YES"<<endl;
		}
	}
	for(i=0;i<q;++i){
		cin>>s>>t;
		x=find(dic[s]);
		y=find(dic[t]);
		if(x==y)
			cout<<1<<endl;
		else if(x==(y^1))
			cout<<2<<endl;
		else
			cout<<3<<endl;
	}
	return 0;
}

