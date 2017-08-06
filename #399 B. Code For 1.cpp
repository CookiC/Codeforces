//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#define LL long long
//#pragma warning(disable : 4996)
using namespace std;

LL n,l,r;
LL M[60],S[60],L[60];

LL Sum(LL x){
	LL ans=0;
	for(int i=0;x;++i){
		if(x>=L[i]){
			if(x>L[i]){
				ans+=M[i-1];
				--x;
			}
			ans+=S[i];
			x-=L[i];
		}
	}
	return ans;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i;
	cin>>n>>l>>r;
	for(i=0;n;++i){
		M[i]=n&1;
		n>>=1;
	}
	n=i;
	S[n-1]=M[n-1];
	L[n-1]=1;
	for(i=n-2;i>=0;--i){
		S[i]=S[i+1]*2+M[i];
		L[i]=L[i+1]*2+1;
	}
	cout<<Sum(r)-Sum(l-1)<<endl;
	return 0;
}

