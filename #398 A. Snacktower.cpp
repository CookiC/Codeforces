//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<queue>
#define maxn 100010
//#pragma warning(disable : 4996)
using namespace std;

int n,t;
priority_queue<int> q;
 
int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n;
	int top=n,i;
	for(i=0;i<n;++i){
		cin>>t;
		q.push(t);
		while(q.top()==top){
			cout<<q.top()<<' '; 
			--top;
			q.pop();
		}
		cout<<endl;
	}
	return 0;
}

