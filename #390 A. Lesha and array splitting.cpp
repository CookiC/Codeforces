//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 110
//#pragma warning(disable : 4996)
using namespace std;

int n;
int a[maxn];
vector<int> L,R;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n;
	for(i=0;i<n;++i)
		cin>>a[i];
	
	int k;
	int i,j,sum;
	i=0;j=0;
	while(j<n){
		sum=0;
		do{
			sum+=a[j++];
		}while(j<n&&!sum);
		while(j<n&&!a[j])
			++j;
		if(sum==0){
			k=0;
			break;
		}
	}
	if(!k)
		cout<<"NO"<<endl;
	else{
		cout<<"YES"<<endl;
		cout<<k<<endl;
		for(i=0;i<L.size();++i)
			cout<<L[i]<<' '<<R[i]<<endl;;
	}
	return 0;
}

