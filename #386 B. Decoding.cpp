//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 2010
//#pragma warning(disable : 4996)
using namespace std;

char c;
int N,L,R;
char s[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>N;
	s[N]=0;
	if(N%2){
		cin>>c;
		s[N/2]=c;
		L=N/2-1;
		R=N/2+1;
	}
	else{
		L=N/2-1;
		R=N/2;
	}
	for(int i=0;i<N;++i){
		if(cin>>c&&L>=0)
			s[L--]=c;
		if(cin>>c&&R<N)
			s[R++]=c;
	}
	cout<<s<<endl;
	return 0;
}

