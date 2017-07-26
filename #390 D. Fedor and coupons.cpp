//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#define maxn 300010
using namespace std;

int n,k,ans,ansL,ansR;
int L[maxn],R[maxn],Li[maxn],Ri[maxn];
bool vis[maxn];

bool cmpL(const int &a,const int &b){
	return L[a]<L[b];
}

bool cmpR(const int &a,const int &b){
	return R[a]<R[b];
}

struct scmpL{
	bool operator ()(const int &a,const int &b){
		if(L[a]==L[b])
			return a<b;
		return L[a]<L[b];
	}
};

set<int,scmpL> p;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j;
	cin>>n>>k;
	for(i=0;i<n;++i){
		cin>>L[i]>>R[i];
		Li[i]=i;
		Ri[i]=i;
	}
	sort(Li,Li+n,cmpL);
	sort(Ri,Ri+n,cmpR);
	
	ans=0;
	i=0;
	j=0;
	p.clear();
	while(i<n&&j<n){
		p.insert(Ri[j]);
		while(i<n&&p.size()<k&&L[Li[i]]<=R[Ri[j]]){
			if(!vis[Li[i]])
				p.insert(Li[i]);
			++i;
		}
		if(p.size()>=k&&R[Ri[j]]-L[*p.rbegin()]+1>ans){
			ans=R[Ri[j]]-L[*p.rbegin()]+1;
			ansL=L[*p.rbegin()];
			ansR=R[Ri[j]];
		}
		p.erase(Ri[j]);
		vis[Ri[j]]=1;
		++j;
	}
	cout<<ans<<endl;
	if(ans){
		int cnt=0;
		for(i=0;i<n&&cnt<k;++i)
			if(L[i]<=ansL&&R[i]>=ansR){
				cout<<i+1<<' '; 
				++cnt;
			}
	}
	else{
		for(i=1;i<=k;++i)
			cout<<i<<' ';
	}
	cout<<endl;
	return 0;
}

