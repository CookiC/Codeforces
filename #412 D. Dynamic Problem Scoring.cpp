//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define LL long long
//#pragma warning(disable : 4996)
using namespace std;

LL n;
LL a[5],b[5],ac[5],p[5];

void score(LL s[5],LL &x,LL &y){
	int i;
	x=0;
	y=0;
	for(i=0;i<5;++i){
		if(a[i]>=0)
			x+=s[i]*(250-a[i])/250;
		if(b[i]>=0)
			y+=s[i]*(250-b[i])/250;
	}
}

bool ok(LL m){
	int i;
	LL cac[5];
	LL s[5];
	for(i=0;i<5;++i)
		cac[i]=ac[i]+p[i]*m;
	m+=n;
	for(i=0;i<5;++i)
		if(m<2*cac[i])
			s[i]=500;
		else if(m<4*cac[i])
			s[i]=1000;
		else if(m<8*cac[i])
			s[i]=1500;
		else if(m<16*cac[i])
			s[i]=2000;
		else if(m<32*cac[i])
			s[i]=2500;
		else
			s[i]=3000;
	LL x,y;
	score(s,x,y);
	if(x>y)
		return true;
	return false;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j;
	LL t;
	cin>>n;
	for(i=0;i<5;++i){
		cin>>a[i];
		if(a[i]>=0)
			++ac[i];
	}
	for(i=0;i<5;++i){
		cin>>b[i];
		if(b[i]>=0)
			++ac[i];
	}
	for(i=2;i<n;++i)
		for(j=0;j<5;++j){
			cin>>t;
			if(t>=0)
				++ac[j];
		}
	for(i=0;i<5;++i)
		if(a[i]>=0&&b[i]>=0&&a[i]>b[i])
			p[i]=1;
		else
			p[i]=0;
	
	LL ans;
	for(ans=0;ans<4000;++ans)
		if(ok(ans))
			break;
	
	if(ans<4000)
		cout<<ans<<endl;
	else
		cout<<-1<<endl;
	return 0;
}
