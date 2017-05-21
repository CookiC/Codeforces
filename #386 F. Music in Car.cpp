//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<set>
#include<vector>
#define maxn 200010
//#pragma warning(disable : 4996)
using namespace std;

int w,n,k,i,j,sum,pl,maxpl;
int a[maxn],t[maxn];
multiset<int> sh,sl;
multiset<int>::iterator p;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n>>w>>k;
	for(i=0;i<n;++i)
		cin>>a[i];
	for(i=0;i<n;++i)
		cin>>t[i];
	
	sum=0;
	i=0;
	j=0;
	pl=0;
	maxpl=0;
	while(j<n){
		if(sh.size()<w){
			sh.insert(t[j]);
			sum+=(t[j]+1)/2;
		}
		else if(t[j]>*sh.begin()){
			sum+=*sh.begin()/2+(t[j]+1)/2;
			sl.insert(*sh.begin());
			sh.erase(sh.begin());
			sh.insert(t[j]);
		}
		else{
			sl.insert(t[j]);
			sum+=t[j];
		}
		pl+=a[j];
		++j;
		
		while(sum>k){
			if(sh.count(t[i])){
				sum-=(t[i]+1)/2;
				sh.erase(sh.find(t[i]));
				if(!sl.empty()){
					p=sl.end();
					--p;
					sum-=*p/2;
					sh.insert(*p);
					sl.erase(p);
				}
			}
			else{
				sum-=t[i];
				sl.erase(t[i]);
			}
			pl-=a[i];
			++i;
		}
		
		if(maxpl<pl)
			maxpl=pl;
	}
	cout<<maxpl<<endl;
	return 0;
}

