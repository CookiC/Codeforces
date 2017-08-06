//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

int l,s,r,p[4],q[4];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i;
	for(i=0;i<4;++i)
		q[i]=1;
	for(i=0;i<4;++i){
		cin>>l>>s>>r>>p[i];
		if(l||s||r)
			q[i]=0;
		if(l)
			q[(i+3)%4]=0;
		if(s)
			q[(i+2)%4]=0;
		if(r)
			q[(i+1)%4]=0;
	}
	bool ans=0;
	for(i=0;i<4;++i)
		if(!q[i]&&p[i]){
			ans=1;
			break;
		}
	if(ans)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}

