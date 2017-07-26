//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxc 1000010 
//#pragma warning(disable : 4996)
using namespace std;

int n,A,B;
int cnt[maxc];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,c;
	cin>>n>>A;
	for(i=0;i<n;++i){
		cin>>c;
		if(cnt[c]>=cnt[A])
			++cnt[c];
		else
			cnt[c]=-1;
	}
	for(i=1;i<maxc;++i)
		if(i!=A&&cnt[i]>=cnt[A])
			break;
	if(i<maxc)
		cout<<i<<endl;
	else
		cout<<-1<<endl;
	return 0;
}

