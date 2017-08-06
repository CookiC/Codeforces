//Author:CookiC
//#include"stdafx.h"
#include<iostream>
//#pragma warning(disable : 4996)
using namespace std;

int n,l,r;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,maxl=0,maxr=0,j,k,suml=0,sumr=0;
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>l>>r;
		suml+=l;
		sumr+=r;
		if(r-l>maxl){
			maxl=r-l;
			j=i;
		}
		if(l-r>maxr){
			maxr=l-r;
			k=i;
		}
	}
	if(maxl==0||maxr==0)
		cout<<0<<endl;
	else{
		if(abs(suml-sumr+2*maxl)>abs(sumr-suml+2*maxr))
			cout<<j<<endl;
		else
			cout<<k<<endl;
	}
	return 0;
}

