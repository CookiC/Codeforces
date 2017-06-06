//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<string>
#define LL long long int
//#pragma warning(disable : 4996)
using namespace std;

LL n,p;
LL ans=0;
LL ten[19];
string s;

void Convert(int *m,LL *x){
	int i=*m,j=0,y=0;
	while(i>=0&&y+(s[i]-'0')*ten[j]<n&&ten[j]<n)
		y=y+(s[i--]-'0')*ten[j++];
	*x=y;
	do{
		--(*m);
		y/=10;
	}while(y);
}
	
int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j;
	LL x;
	ten[0]=1;
	for(i=1;i<19;++i)
		ten[i]=ten[i-1]*10;
	
	cin>>n>>s;
	p=1;
	x=0;
	i=s.size()-1;
	while(i>=0){
		Convert(&i,&x);
		ans+=p*x;
		p*=n;
	}
	
	cout<<ans<<endl;
	return 0;
}

