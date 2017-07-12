//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
#define maxn 10010
//#pragma warning(disable : 4996)
using namespace std;

vector<int> rmq[maxn];

void RMQInit(int *a,int l){
	int i,j;
	for(i=0;i<l;++i){
		rmq[i].clear();
		rmq[i].push_back(a[i]);
	}
	for(j=1;(1<<j)<l;++j)
		for(i=0;i+(1<<j)-1<l;++i)
			rmq[i].push_back(min(rmq[i][j-1],rmq[i+(1<<j-1)][j-1]));
} 

int RMQ(int L,int R){
	int k=0;
	while((1<<(k+1))<=R-L+1)
		++k;
	return min(rmq[L][k],rmq[R-(1<<k)+1][k]);
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int a[]={1,3,2,4,2,4,5,2,7,7,5,3,2,1};
	RMQInit(a,14);
	return 0;
}

