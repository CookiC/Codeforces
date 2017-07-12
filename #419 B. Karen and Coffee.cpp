//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
#define lowbit(n) (n&-n) 
#define maxn 200010
//#pragma warning(disable : 4996)
using namespace std;

const int N=maxn;
int C[maxn];
vector<int> a;

int Sum(unsigned n){
	int sum=0;
	while(n>0){
		sum+=C[n];
		n-=lowbit(n);
	}
	return sum;
}

void Add(unsigned n,int d){
	while(n<=N){
		C[n]+=d;
		n+=lowbit(n);
	}
}

void Add(int L,int R,int d){
	Add(L,d);
	Add(R+1,-d);
}

int n,k,q;

void Update(){
	int t;
	for(int i=1;i<=N;++i){
		t=Sum(i);
		if(t>=k)
			a.push_back(i);
	}
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,l,r;
	cin>>n>>k>>q;
	for(i=0;i<n;++i){
		cin>>l>>r;
		Add(l,r,1);
	}
	Update();
	int ans;
	for(i=0;i<q;++i){
		cin>>l>>r;
		ans=upper_bound(a.begin(),a.end(),r)-lower_bound(a.begin(),a.end(),l);
		cout<<ans<<endl;
	}
	return 0;
}

