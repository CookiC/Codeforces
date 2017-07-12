//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
#define maxn 200010
//#pragma warning(disable : 4996)
using namespace std;

struct Vacation{
	int l,r,cost;
};

Vacation a[maxn];
vector<Vacation*> v[maxn];
int n,x;

bool cmpR(const Vacation &a,const Vacation &b){
	if(a.r==b.r)
		return a.cost<b.cost;
	return a.r<b.r;
} 

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j,maxR=0;
	cin>>n>>x;
	for(i=0;i<n;++i)
		cin>>a[i].l>>a[i].r>>a[i].cost;
	sort(a,a+n,cmpR);
	
	for(i=0;i<n;++i){
		int d=a[i].r-a[i].l+1;
		if(d>0&&!v[d].size()||a[i].cost<(*v[d].rbegin())->cost)
			v[d].push_back(&a[i]);
	}
	
	int ans=0x7FFFFFFF;
	for(i=0;i<n;++i){
		int d=x-(a[i].r-a[i].l+1);
		if(d>0&&v[d].size()){
			vector<Vacation*> &t=v[d];
			int L=1;
			int R=t.size()+1;
			int M;
			while(L<R){
				M=L+(R-L)/2;
				if(t[M-1]->r<a[i].l)
					L=M+1;
				else
					R=M;
				
			}
			if(L-1)
				ans=min(ans,t[L-2]->cost+a[i].cost);
		}
	}
	if(ans==0x7FFFFFFF)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
	return 0;
}

