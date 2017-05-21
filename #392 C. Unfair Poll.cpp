//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define LL long long
//#pragma warning(disable : 4996)
using namespace std;

LL n,m,k,x,y,M;
LL mina,maxa,ser;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	LL a,b,c;
	cin>>n>>m>>k>>x>>y;
	if(n==1||n==2){
		M=n*m;
		a=k/M;
		ser=mina=maxa=a;
	}
	else{
		M=(n*2-2)*m;
		a=k/M; 
		mina=a;
		maxa=2*a;
		if(x!=1&&x!=n)
			ser=maxa;
		else
			ser=mina;
	}
	
	a=k%M;
	if(a){
		--a;
		--x;
		--y;
		b=a/m;
		c=a%m;
		if(n==1||n==2)
			++maxa; 
		else{
			if(b)
				++maxa;
			if(b>n-1)
				++maxa;
			if(b>n-1||b==n-1&&c==m-1)
				++mina;
			if(x<n-1&&(b-(n-1)>(n-1)-x||b-(n-1)==(n-1)-x&&c>=y))
				++ser;
		}
		if(b>x||b==x&&c>=y)
			++ser;		
	}
	if(!maxa)
		maxa=1;
	cout<<maxa<<' '<<mina<<' '<<ser<<endl;
	return 0;
}

